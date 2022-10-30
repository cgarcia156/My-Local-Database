#include "../includes/sql.h"

// constructor for SQL
SQL::SQL() : _table_names("Table Names"), p("") {
  // Add our table of table names to tables 
  _tables["Table Names"] = _table_names;

  // Display tables managed by SQL
  Vector<string> table_names = _table_names["Name"];
  cout << "\n\n------ SQL Tables I Manage: --------\n";
  for (int i = 0; i < table_names.size(); ++i) {
    _tables[table_names[i]] = Table(table_names[i]);
    cout << table_names[i] << endl;
  }
  cout << "------------------------------------\n\n";
}

void SQL::run() {
  bool DEBUG = false;
  // display options
  cout << "\n\nEnter an SQL command (create/select/insert/delete/drop)\n"
       << "OR\n"
       << "Batch a file with the command: batch file_name.txt\n\n\n"
       << "Enter exit to quit the program\n\n\n";

  get_sql_command();

  if (DEBUG) {
    cout << "Input String: " << s << endl;
  }

  // Loop until finished
  while (s != "EXIT" && s != "exit" && s != "Exit") {
    // check for batch command
    string batch_check;
    batch_check.assign(s, 0, 5);
    if (batch_check == "batch") {
      run_batch();
      get_sql_command();
    } else {

      // Process the input
      run_command();

      // Get the next input and reset parser
      get_sql_command();
    }
  }
}

void SQL::run_batch() {
  ifstream f;
  // grab file name
  s.assign(s, 6, s.size() - 6);

  f.open(s, fstream::in);
  // check for file failure
  if (f.fail()) {
    cout << "\n\nFile [" << s;
    cout << "] Does Not Exist\n\n";
  } else {
    int command_num = 0;

    // read through file and run command
    getline(f, s);
    while (!f.eof()) {
      p.set_buffer(s);
      p.set_string();
      pTree = p.parse_tree();
      fail = p.fail();
      // only run if command is valid
      if (!fail) {
        cout << "[" << command_num << "] " << s << endl;
        run_command();
        command_num++;
      } else {
        cout << s << endl;
      }
      getline(f, s);
    }
    f.close();
  }
}

void SQL::run_command() {
  bool DEBUG = false;

  if (DEBUG) {
    cout << pTree;
  }

  if (fail) {
    cout << "\n\nERROR: INVALID INPUT\n\n";
  } else {
    // If command is SELECT
    if (p.get_column(pTree["command"][0]) == p.SELECT) {
      select();
    }
    // If command is CREATE
    if (p.get_column(pTree["command"][0]) == p.CREATE) {
      create_table();
    }
    // If command is INSERT
    if (p.get_column(pTree["command"][0]) == p.INSERT) {
      insert();
    }
    // If command is DROP
    if (p.get_column(pTree["command"][0]) == p.DROP) {
      drop_table();
    }
    // If command is DELETE
    if (p.get_column(pTree["command"][0]) == p.DELETE) {
      delete_where();
    }
  }
}

void SQL::select() {
  string table_name = pTree["table"][0];
  // Make sure table exists
  if (_tables.contains(table_name)) {
    Table t = _tables[table_name];
    // call proper table select function
    if (pTree.contains("where")) {
      if (pTree["fields"][0] == "*") {
        cout << t.select_where(pTree["condition"]);
        cout << endl << endl;
      } else {
        cout << t.select(pTree["fields"], pTree["condition"]);
        cout << endl << endl;
      }
    } else if (pTree["fields"][0] == "*") {
      cout << t.select_all();
      cout << endl << endl;
    } else {
      cout << t.select(pTree["fields"]);
      cout << endl << endl;
    }
  } else {
    cout << "\n\nTable Not Found\n\n";
  }
}

void SQL::insert() {
  bool DEBUG = false;
  string table_name = pTree["table"][0];
  // check existence of table
  if (_tables.contains(table_name)) {
    // call insert_into() from table
    _tables[table_name].insert_into(pTree["values"]);
    cout << "SQL::Insertion Complete\n\n";
    if (DEBUG) {
      cout << _tables[table_name];
    }

  } else {
    cout << "\n\nTable Not Found\n\n";
  }
}

void SQL::drop_table() {
  bool DEBUG = false;
  string table_name = pTree["table"][0];
  // check existence of table
  if (table_name == "Table Names") {
    cout << "\n\n[Table Names] Cannot Be Deleted\n\n";
  } else if (_tables.contains(table_name)) {
    // delete the table and remove it from our records
    _tables.erase(table_name);
    _table_names.delete_where({"Name", "=", table_name});
    string file_name = table_name + ".bin";
    remove(file_name.c_str());
    cout << "Table [" << table_name;
    cout << "] has been deleted\n\n";

    if (DEBUG) {
      // prints out current tables managed by sql
      Map<string, Table>::Iterator it;
      for (it = _tables.begin(); it != _tables.end(); ++it) {
        cout << (*it).key << endl;
      }
      cout << endl;
    }
    
  } else {
    cout << "\n\nTable [" << table_name;
    cout << "] Not Found\n\n";
  }
}

void SQL::delete_where() {
  bool DEBUG = false;
  string table_name = pTree["table"][0];
  // check existence of table
  if (_tables.contains(table_name)) {
    // call the delete_where() from table
    _tables[table_name].delete_where(pTree["condition"]);
    cout << "SQL::Deletion Complete\n\n";
    if (DEBUG) {
      cout << _tables[table_name];
    }
  } else {
    cout << "\n\nTable [" << table_name;
    cout << "] Not Found\n\n";
  }
}

void SQL::create_table() {
  bool DEBUG = false;
  string table_name = pTree["table"][0];
  // make sure table doesn't already exist
  if (!_tables.contains(table_name)) {
    // create a new table and store its name
    _tables[table_name] = Table(table_name, pTree["fields"]);
    _table_names.insert_into({table_name});
    _tables["Table Names"] = _table_names;
    cout << "SQL::Table [" << table_name << "] has been created\n\n";
  } else {
    cout << "\n\nTable [" << table_name;
    cout << "] Already Exists\n\n";
  }

  if (DEBUG) {
    cout << _tables[table_name];
  }
}

bool SQL::get_sql_command() {
  cout << ">";
  getline(cin, s);
  // update parser/ptree
  p.set_buffer(s);
  p.set_string();
  pTree = p.parse_tree();
  // set fail
  fail = p.fail();
  return fail;
}