/*
 * Author: Christian Garcia
 * 
 * Project: String Tokenizer(Table Declarations)
 * 
 */

#ifndef S_TABLE_H_
#define S_TABLE_H_

#include <iostream>
using namespace std;

#define MAX_ROWS 51
#define MAX_COLUMNS 128
#define MAX_BUFFER 500

void init_table(int array[MAX_ROWS][MAX_COLUMNS]);
void mark_success(int row, int array[MAX_ROWS][MAX_COLUMNS]);
void mark_cells(int row, int array[MAX_ROWS][MAX_COLUMNS], int start, int end, int value);
void mark_cells(int row, int array[MAX_ROWS][MAX_COLUMNS], string columns, int value);
void append(char* string, char c);
void append(string&, char);

#endif //S_TABLE_H_

