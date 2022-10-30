/*
 * Author:  Christian Garcia
 * Project: String Tokenizer (Token Implementation)
 * Purpose: Displays type of token as a string based
 *          on the acceptable token types
 * 
 */

#include "../includes/token.h"
//States of acceptable token types
enum Type {
UNKNOWN = 0, FOREIGN = 5, SPACE = 10, ALPHA = 20, PUNCTUATION = 30, OPERATOR = 31, OPERATOR2, OPERATOR3, BRACKET, STRING = 36, NUMBER = 40, DECIMAL = 42
};
//displays token in | |
ostream& operator <<(ostream& outs, const Token& t) {
    outs << "|" <<
    t._token << "|" << endl;
    return outs;
}
//returns type of token
int Token::type() {
    return _type;
}
//displays the type of token as a string
string Token::type_string() {
    switch (_type) {
        case ALPHA:
            return "ALPHA";
            break;
        case FOREIGN:
            return "FOREIGN";
            break;
        case NUMBER:
            return "NUMBER";
            break;
        case SPACE:
            return "SPACE";
            break;
        case PUNCTUATION:
            return "PUNC";
            break;
        case DECIMAL:
            return "DECIMAL";
            break;
        case UNKNOWN:
            return "UNKNOWN";
            break;
        case STRING:
            return "STRING";
            break;
        case OPERATOR:
            return "OPERATOR";
            break;
        case OPERATOR2:
            return "OPERATOR";
            break;
        case OPERATOR3:
            return "OPERATOR";
            break;
        case BRACKET:
            return "BRACKET";
            break;
        default:
            return "UNKNOWN";
    }   
}
//returns the token
string Token::token_str() {
    return _token;
}
