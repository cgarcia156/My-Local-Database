#include "../includes/stokenizer.h"

int STokenizer::_table[MAX_ROWS][MAX_COLUMNS];

STokenizer::STokenizer() : _pos(0) {
    _buffer[0] = '\0';
    make_table(_table);
}

STokenizer::STokenizer(char str[]) : _pos(0) {
    _bufferLength = strlen(str);
    set_string(str);
    make_table(_table);
}

bool STokenizer::done() {
    return (_pos>=(_bufferLength+1)) ? true:false;
}

bool STokenizer::more() {
    return (_pos<(_bufferLength+1))? true:false;
}

STokenizer& operator >> (STokenizer& s, Token& t) {
    s.sToken = t.token_str();
    if(s.get_token(s._state,s.sToken)) {
    t = Token(s.sToken,s._state);
    } else {
        s._pos = s._bufferLength+1;
    }
    return s;
    
}
//sets a new buffer
void STokenizer::set_string(char str[]) {
    int len = strlen(str);
    for(int i=0; _buffer[i]!='\0'; i++) {
        _buffer[i] = '\0';
    }
    _bufferLength = len;
    _pos = 0;
    for(int i=0; i<len; i++) {
        _buffer[i] = str[i];
    } 
    _buffer[len] = '\0';
}