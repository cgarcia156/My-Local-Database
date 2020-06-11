#include <iostream>
#include <fstream>
#include "record.h"
using namespace std;

long Record::write(fstream &outs){
    //write to the end of the file.
    outs.seekg(0, outs.end);
    long pos = outs.tellp();

    outs.write(&record[0][0], sizeof(record));

    return pos/sizeof(record);
}
void Record::write(fstream &outs,long rec){
    outs.seekg(sizeof(record)*rec,outs.beg);

    outs.write(&record[0][0], sizeof(record));
}
long Record::read(fstream &ins, long recno){
    long pos= recno * sizeof(record);
    ins.seekg(pos, ios_base::beg);

    ins.read(&record[0][0], sizeof(record));
    return ins.gcount();

}
ostream& operator<<(ostream& outs,
                    const Record& r){
    for (int i=1; i<r._num_of_fields; i++){
        outs<<left<<setw(16)<<r.record[i]<<"|";
    }
    return outs;
}

//-------------------------------------------------
bool file_exists(const char filename[]){
    const bool debug = false;
    fstream ff;
    ff.open (filename,
        std::fstream::in | std::fstream::binary );
    if (ff.fail()){
        if (debug) cout<<"file_exists(): File does NOT exist: "<<filename<<endl;
        return false;
    }
    if (debug) cout<<"file_exists(): File DOES exist: "<<filename<<endl;
    ff.close();
    return true;
}

void open_fileRW(fstream& f, const char filename[]) {
    const bool debug = false;
    //openning a nonexistent file for in|out|app causes a fail()
    //  so, if the file does not exist, create it by openning it for
    //  output:
    if (!file_exists(filename)){
        f.open(filename, std::fstream::out|std::fstream::binary);
        if (f.fail()){
            cout<<"file open (RW) failed: with out|"<<filename<<"]"<<endl;
            throw("file RW failed  ");
        }
        else{
            if (debug) cout<<"open_fileRW: file created successfully: "<<filename<<endl;
        }
    }
    else{
        f.open (filename,
            std::fstream::in | std::fstream::out| std::fstream::binary );
        if (f.fail()){
            cout<<"file open (RW) failed. ["<<filename<<"]"<<endl;
        }
    }

}
void open_fileW(fstream& f, const char filename[]){
    f.open (filename,
            std::fstream::out| std::fstream::binary );
    if (f.fail()){
        cout<<"file open failed: "<<filename<<endl;
        throw("file failed to open.");
    }

}