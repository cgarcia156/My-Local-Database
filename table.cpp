
#include "table.h"

#include "rpn.h"
#include "shunting_yard.h"

//---------------------Constructors-----------------------
Table::Table(const Table& RHS) {
  _name = RHS._name;
  _field_list = RHS._field_list;
  _file_name = RHS._file_name;
  _field_map = RHS._field_map;
  _indices = RHS._indices;
  _last_record = RHS._last_record;
  _num_of_deleted = RHS._num_of_deleted;
}

Table::Table(const string& name, const Vector<string> field_list, bool temp) {
  fstream f;
  _name = name;
  _field_list += "Deleted";
  _field_list += field_list;
  if (temp) {
    string s = to_string(serial);
    serial++;
    _file_name = ("_" + _name + s + ".bin");
  } else {
    _file_name = (name + ".bin");
  }

  _last_record = 0;
  _num_of_deleted = 0;

  initialize_maps(_field_list);

  open_fileW(f, _file_name.c_str());
  Record r(_field_list);
  r.write(f);
  (f).close();
}

Table::Table(const string& name) {
  // Initialize variables
  fstream f;
  _name = name;
  _last_record = 0;
  _num_of_deleted = 0;
  _file_name = (name + ".bin");
  long recno = 0;
  Record r;

  // Grab the fields from record 0
  open_fileRW(f, _file_name.c_str());
  r.read(f, recno);
  _field_list = r.get_record();
  (f).close();

  // Init maps and reindex
  initialize_maps(_field_list);
  reindex();
}

//---------------------Destructor-------------------------
Table::~Table() {
  if (_file_name[0] == '_') {
    remove(_file_name.c_str());
  }
}

//--------------------Main Commands-----------------------
Table Table::select(Vector<string> fields) {
  fstream f;
  Vector<string> tfields({"Deleted"});
  tfields += fields;
  Record r(tfields);

  Table t = Table(_name, fields, true);

  Vector<string> record;

  Vector<int> columns = get_columns(fields);

  open_fileRW(f, _file_name.c_str());
  for (int i = 1; i <= _last_record; i++) {
    r.read(f, i);
    record = r.get_record();
    if (record[0] != "1") {
      record = record.pick(columns);
      t.insert_into(record);
    }
  }
  (f).close();
  return t;
}

Table Table::select(Vector<string> fields, Vector<string> condition) {
  fstream f;
  Vector<string> tfields({"Deleted"});
  tfields += fields;
  Record r(tfields);
  Table t = Table(_name, fields, true);

  Vector<long> indices = get_indices(condition, _indices);

  Vector<int> columns = get_columns(fields);

  open_fileRW(f, _file_name.c_str());
  for (int i = 0; i < indices.size(); ++i) {
    r.read(f, indices[i]);
    t.insert_into(r.get_record().pick(columns));
  }
  f.close();
  return t;
}

Table Table::select_where(Vector<string> condition) {
  fstream f;
  Record r(_field_list);
  Table t = Table(_name, _field_list.ignore(0), true);

  Vector<long> indices = get_indices(condition, _indices);

  open_fileRW(f, _file_name.c_str());
  for (int i = 0; i < indices.size(); ++i) {
    r.read(f, indices[i]);
    t.insert_into(r.get_record().ignore(0));
  }
  f.close();
  return t;
}

Table Table::select_all() {
  fstream f;
  Table t = Table(_name, _field_list.ignore(0), true);
  Vector<string> record;
  Record r(_field_list);

  open_fileRW(f, _file_name.c_str());

  for (int i = 1; i <= _last_record; ++i) {
    r.read(f, i);
    record = r.get_record();
    if (record[0] != "1") {
      record = record.ignore(0);
      t.insert_into(record);
    }
  }
  f.close();

  t.reindex();
  return t;
}

void Table::delete_where(Vector<string> condition) {
  Vector<long> indices = get_indices(condition, _indices);

  for (int i = 0; i < indices.size(); ++i) {
    del(indices[i]);
  }

  reindex();
}

void Table::insert_into(Vector<string> field_list) {
  fstream f;
  open_fileRW(f, _file_name.c_str());
  Vector<string> fields;
  fields += "0";
  fields += field_list;
  Record r(fields);
  long recno = r.write(f);
  _last_record = recno;
  push_to_indices(fields, recno);
  (f).close();
}

//-------------------Helper Functions---------------------
void Table::initialize_maps(const Vector<string> field_list) {
  for (int i = 0; i < field_list.size(); ++i) {
    _indices[field_list[i]] = MMap<string, long>();
    _field_map[field_list[i]] += i;
  }
}

void Table::reindex() {
  fstream f;
  Vector<string> field_list;
  long recno = 1;
  _num_of_deleted = 0;
  _last_record = 0;
  Record r;
  _indices.clear();

  open_fileRW(f, _file_name.c_str());
  r.read(f, recno);

  while (!f.eof()) {
    _last_record++;
    field_list = r.get_record();
    if (field_list[0] != "1") {
      push_to_indices(field_list, recno);
    } else {
      _num_of_deleted++;
    }

    recno++;
    r.read(f, recno);
  }
  (f).close();
}

void Table::push_to_indices(const Vector<string> fields, long recno) {
  for (int i = 0; i < fields.size(); ++i) {
    _indices[_field_list[i]][fields[i]] += recno;
  }
}

void Table::del(long index) {
  fstream f;
  open_fileRW(f, _file_name.c_str());
  Vector<string> record;
  Record r(_field_list);
  r.read(f, index);
  record = r.get_record();
  record[0] = "1";
  r = Record(record);
  r.write(f, index);
  f.close();
}

Vector<int> Table::get_columns(Vector<string> fields) {
  Vector<int> columns;
  for (int i = 0; i < fields.size(); ++i) {
    columns.push(_field_map[fields[i]]);
  }
  return columns;
}

Vector<long> Table::get_indices(Vector<string> condition,
                                Map<string, MMap<string, long> > indices) {
  SY sy(condition);
  if(sy.fail()) {
    return Vector<long> ();
  } else {
  RPN rpn(indices, sy.get_postfix());
  return rpn.evaluate();
  }
}

void Table::print(ostream& outs) const {
  Record r(_field_list);
  fstream f;
  open_fileRW(f, _file_name.c_str());
  long recno = 0;
  long record = 0;
  outs << endl
       << left << setw(16) << _name
       << "Records: " << _last_record - _num_of_deleted << endl
       << endl;
  r.read(f, recno);
  outs << setw(16) << "Record" << "|" << r << endl;
  for (int i = 0; i < _field_list.size(); ++i) {
    outs << "-----------------";
  }
  outs << endl;
  recno++;
  r.read(f, recno);
  while (!(f).eof()) {
    if (r.get_record()[0] != "1") {
      outs << left << setw(16) << record <<
       "|" << r << endl;
      record++;
    }
    recno++;
    r.read(f, recno);
  }
  outs << endl;
  (f).close();
}

//---------------------Operators--------------------------
Table Table::operator=(const Table& RHS) {
  _name = RHS._name;
  _field_list = RHS._field_list;
  _file_name = RHS._file_name;
  _field_map = RHS._field_map;
  _indices = RHS._indices;
  _last_record = RHS._last_record;
  _num_of_deleted = RHS._num_of_deleted;
  return *this;
}

Vector<string> Table::operator[](string field) {
  fstream f;
  Vector<string> info;
  Vector<string> record;
  open_fileRW(f, _file_name.c_str());
  Record r(_field_list);
  for (int i = 1; i <= _last_record; ++i) {
    r.read(f, i);
    record = r.get_record();
    if (record[0] != "1") {
      info += record[_field_map[field]];
    }
  }
  f.close();
  return info;
}
