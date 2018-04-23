#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>

class Message {
    
public:
    static const std::string CONSOLE_prompt;
    static const std::string PROGRAM_information;
    static const std::string MENU_description;
    static const std::string MENU_wrongInput;
    static const std::string FILE_getFilename;
    static const std::string FILE_loadSuccess;
    static const std::string FILE_loadFailure;
    static const std::string SALESMAN_displayAllItems;
    static const std::string SALESMAN_dynamicProgramming;
};

#endif //MESSAGE_H
