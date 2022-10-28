/*
 * Author:  Christian Garcia
 * Project: String Tokenizer (Table Implementation)
 * Purpose: Functions used to create/modify a table(2d array)
 *          Also has functions to make appending easier
 */

#include "../includes/sTable.h"

//sets every column to -1 except first column
void init_table(int array[MAX_ROWS][MAX_COLUMNS]) {
for (int i=0;i<MAX_ROWS;i++) {
        for(int j=0;j<MAX_COLUMNS;j++) {
        array[i][j] = -1;
    }
}
for (int i=0;i<MAX_ROWS;i++) {
    array[i][0] = 0;
}
}
//sets the first index in a certain row to 1
void mark_success(int row, int array[MAX_ROWS][MAX_COLUMNS]) {
    array[row][0] = 1;
}
//mark a range of columns at a certain row
void mark_cells(int row, int array[MAX_ROWS][MAX_COLUMNS], int start, int end, int value) {
    for(int j=start;j<=end;j++) {
        array[row][j] = value;
    }
}
//assign a value to each column at a certain row
void mark_cells(int row, int array[MAX_ROWS][MAX_COLUMNS], string columns, int value) {
    for(int j=0;columns[j]!='\0';j++) {
        char temp = columns[j];
        array[row][(int)temp] = value;
    }
}
//adds a character to a c string
void append(char* string, char c) {
        int len = strlen(string);
        string[len] = c;
        string[len+1] = '\0';
}
//adds a character to a string
void append(string &string, char c) {
    std::string s(1,c);
    string.append(s);
}