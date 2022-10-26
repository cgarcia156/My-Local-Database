#ifndef TABLE_H_
#define TABLE_H_

#include <fstream>
#include <iostream>

#include "data_structures/vector.h"
#include "data_structures/map.h"
#include "data_structures/mmap.h"
#include "record.h"

using namespace std;

static int serial = 1000;
class Table {
 public:
  //---------------------Constructors-----------------------
  Table() {}
  Table(const string& name, const Vector<string> field_list, bool temp = false);
  Table(const string& name);
  Table(const Table& RHS);
  //---------------------Destructor-------------------------
  ~Table();
  //--------------------Main Commands-----------------------
  void insert_into(Vector<string> field_list);
  Table select_all();
  Table select(Vector<string> fields);
  Table select(Vector<string> fields, Vector<string> condition);
  Table select_where(Vector<string> condition);
  void delete_where(Vector<string> condition);
  //-------------------Helper Functions---------------------
  void reindex();
  void initialize_maps(const Vector<string> field_list);
  void push_to_indices(const Vector<string> fields, long recno);
  Vector<int> get_columns(Vector<string> fields);
  Vector<long> get_indices(Vector<string> condition,
                           Map<string, MMap<string, long> > indices);
  void del(long index);
  void print(ostream& outs) const;
  //---------------------Operators--------------------------
  Table operator=(const Table& RHS);
  Vector<string> operator[](string field);
  friend ostream& operator<<(ostream& outs, const Table& print_me) {
    print_me.print(outs);
    return outs;
  }

 private:
  string _name;
  Vector<string> _field_list;
  string _file_name;
  Map<string, int> _field_map;
  Map<string, MMap<string, long> > _indices;
  long _last_record;
  long _num_of_deleted;
};

#endif  // TABLE_H_
