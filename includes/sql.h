#ifndef SQL_
#define SQL_

#include <iostream>

#include "parser.h"
#include "table.h"

class SQL {
 public:
  //----------Constructor-------------
  SQL();
  //----------Run Functions-----------
  void run();
  void run_batch();
  void run_command();
  bool get_sql_command();
  //----------Main Commands-----------
  void select();
  void insert();
  void create_table();
  void drop_table();
  void delete_where();
 private:
  //-----------Variables--------------
  MMap<string,string> pTree;
  Map<string,Table> _tables;
  Table _table_names;
  string file;
  Parser p;
  bool fail;
  string s;
};

#endif  // SQL_
