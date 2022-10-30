/*
 * Author: Christian Garcia
 * 
 * Project: String Tokenizer(Token declarations)
 * 
 */

#ifndef TOKEN_H_
#define TOKEN_H_

#include <iostream>
#include <string>

using namespace std;

class Token
{
public:
    Token() : _token(""), _type(0){
    }
    Token(string str, int type) : _token(str), _type(type) {
    }
    friend ostream& operator <<(ostream& outs, const Token& t);
    int type();
    string type_string();
    string token_str();

private:
    string _token;
    int _type;
};

#endif  // TOKEN_H_


