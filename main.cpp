/*
 * Author: Christian Garcia
 * Project: Database
 * Purpose: Table,Parser, and SQL work together to take input
 *          and execute the desired commands. Table class is
 *          used to work with tables which are stored in binary
 *          files. SQL uses Parser to help find the command,fields,etc.
 *          and calls the proper table functions
 *
 */

#include <iostream>

#include "../Includes/sql.h"

int main() {
  SQL sql;
  sql.run();

  cout << "\n----------------End---------------\n\n";
}