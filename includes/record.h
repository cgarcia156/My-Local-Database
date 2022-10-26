#ifndef RECORD_H_
#define RECORD_H_

#include <iostream>
#include <fstream>
#include "data_structures/vector.h"
using namespace std;

bool file_exists(const char filename[]);

void open_fileRW(fstream& f, const char filename[]);
void open_fileW(fstream& f, const char filename[]);

typedef Vector<string> vectorstr;

class Record{
public:
    Record(){
        for (int i= 0; i<_MAX_ROWS; i++)
            record[i][0] = '\0';
        recno = -1;
        _num_of_fields = 0;
    }

//    Record(char str[]){
//        strcpy(record, str);
//    }
    Record(const vectorstr& v){
        for (int i= 0; i<_MAX_ROWS; i++)
            record[i][0] = '\0';
        for (int i= 0; i<v.size(); i++){
            strcpy(record[i], v[i].c_str());
        }
        _num_of_fields = v.size();
    }
    vectorstr get_record(){
        vectorstr v;
        //cout<<" get_record(): "<<_num_of_fields<<endl;
        for (int i = 0; i<_MAX_ROWS; i++){
            string s = record[i];
            if(!s.empty()) {
            v.push(s);
            }
        }
        return v;
    }
    long write(fstream& outs);
    void write(fstream& outs, long rec);
    long read(fstream& ins, long recno);


    friend ostream& operator<<(ostream& outs,
                               const Record& r);
private:
    static const int _MAX_ROWS = 8;
    static const int _MAX_COLS = 16;
    int recno;
    int _num_of_fields;
    char record[_MAX_ROWS][_MAX_COLS];
};

template<typename T>
ostream& operator <<(ostream& outs, const Vector<T>& v){
    for (int i = 0; i<v.size(); i++){
        outs<<v[i]<<" ";
    }
    return outs;
}


#endif  // RECORD_H_
