#ifndef FILE_H
#define FILE_H

#include <fstream>

class File {
    
public:
    std::fstream fstream;
    
    void open(std::string filename);
    void close();
    
    bool isOpen();
    bool eof();
    
    void setPointerPosition(long position);
    long getPointerPosition();
    
    int getInt();
    std::string getLine();
    std::string getString();
};

#endif //FILE_H
