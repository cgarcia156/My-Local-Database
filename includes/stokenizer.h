/*
 * Author: Christian Garcia
 * 
 * Project: String Tokenizer(STokenizer declarations)
 * 
 */

#ifndef STOKENIZER_H_
#define STOKENIZER_H_

#include "token.h"
#include "st_table.h"

#define MAX_ROWS 51
#define MAX_COLUMNS 128
#define MAX_BUFFER 500

class STokenizer
{
public:
    string sToken;
    STokenizer();
    STokenizer(char str[]);
    bool done();            //true: there are no more tokens
    bool more();            //true: there are more tokens

    //extract one token
    friend STokenizer& operator >> (STokenizer& s, Token& t);

    //set a new string as the input string
    void set_string(char str[]);

private:
    //create table for all the tokens we will recognize
    void make_table(int _table[][MAX_COLUMNS]) {
        //sets first column to 0 and everything else to -1
        init_table(_table);
        //mark success states
        mark_success(10,_table);
        mark_success(20,_table);
        mark_success(30,_table);
        mark_success(31,_table);
        mark_success(32,_table);
        mark_success(33,_table);
        mark_success(34,_table);
        mark_success(36,_table);
        mark_success(40,_table);
        mark_success(42,_table);
        //create state for spaces
        mark_cells(0,_table," \n\t\b\r",10);
        //create state for brackets
        mark_cells(0,_table,"()",34);
        //create state for punctuations
        mark_cells(0,_table,";:.,|{}[]\'`-!?&@#",30);
        mark_cells(0,_table,">=",31);
        mark_cells(0,_table,"<",33);
        mark_cells(0,_table,"\"",35);
        //create state for numbers
        mark_cells(0,_table,'0','9',40);
        //create state for letters
        mark_cells(0,_table,'A','Z',20);
        mark_cells(0,_table,'a','z',20);
        //stay at state 10 while char is a space
        mark_cells(10,_table," \n\t\b\r",10);
        //stay at state 40 while char is a number
        mark_cells(40,_table,'0','9',40);
        //case for doubles
        mark_cells(40,_table,'.','.',41);
        mark_cells(41,_table,'0','9',42);
        mark_cells(42,_table,'0','9',42);
        //stay at state 20 while char is a letter
        mark_cells(20,_table,'A','Z',20);
        mark_cells(20,_table,'a','z',20);
        //stay at state 30 while char is a punctuation
        mark_cells(30,_table,";:.,|{}[]\'`-!?&@#",30);
        //operators
        mark_cells(31,_table,"=",32);
        mark_cells(33,_table,">=",32);
        //stay at 35 until another "
        mark_cells(35,_table,'A','Z',35);
        mark_cells(35,_table,'a','z',35);
        mark_cells(35,_table,";:.,{}|/\\[]'()`-!?&@# _=+~%$",35);
        mark_cells(35,_table,'0','9',35);
        mark_cells(35,_table,"\"",36);
    }
    //extract the longest string that matches
    //   one of the acceptable token types
    bool get_token(int &state, string& token) {
    char* temptoken = new char[MAX_BUFFER];
    char input;
    int iterator = _pos;
    state=0;
    int row = state;
    //check for foreign letters
    if(_buffer[iterator]<0) {
        char temp[] = "";
        char c = _buffer[iterator];
        append(temp,c);
        token = temp;
        state = 5;
        _pos++;
        return true;
    }
    //get largest acceptable token type
    row = _table[row][(int)_buffer[iterator]];
    while(row>=0&&(int)_buffer[iterator]>0) {
        input = _buffer[iterator];
        append(temptoken,input);
        if(_table[row][0] == 1) {
          state = row;
          token = temptoken;
          _pos = iterator;
          
        }
        iterator++;
        row = _table[row][(int)_buffer[iterator]];
    }

    //if no tokens found, char is unknown
    if(token=="") {
        char c = _buffer[iterator];
        append(token,c);
        state = 0;
        _pos++;
        return true;
    }

    _pos++;
    //return false only if the pos has gone through the whole buffer
    return (!done());
}
    //---------------------------------
    int _bufferLength;
    int _state;
    char _buffer[MAX_BUFFER];       //input string
    int _pos;                       //current position in the string
    static int _table[MAX_ROWS][MAX_COLUMNS];
};

#endif //STOKENIZER_H_