#include "file.h"

void File::open(std::string filename) {
    fstream.close();
    fstream.open(filename);
}

void File::close() {
    fstream.close();
}

bool File::isOpen() {
    return (bool) fstream;
}

bool File::eof() {
    return fstream.eof();
}

void File::setPointerPosition(long position) {
    fstream.clear();
    fstream.seekg(position);
}

long File::getPointerPosition() {
    return fstream.tellg();
}

int File::getInt() {
    int get;
    fstream >> get;
    return get;
}

std::string File::getLine() {
    std::string line;
    std::getline(fstream, line);
    return line;
}

std::string File::getString() {
    std::string get;
    fstream >> get;
    return get;
}
