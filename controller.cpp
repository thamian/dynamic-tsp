#include "controller.h"

void Controller::start() {
    Console::println(Message::PROGRAM_information);
    Console::println();
    Console::println(Message::MENU_description);

    bool exit = false;
    while (!exit) {
        Console::print(Message::CONSOLE_prompt);
        switch (Convert::toInt(Console::getInput())) {
            case 0: {                   // Lista dostępnych opcji.
                Console::println(Message::MENU_description);
            } break;
            case 1: {                   // Problem komiwojażera
                travellingSalesmanProblem();
            } break;
            case 2: {                   // Wyjście.
                exit = true;
            } break;
            default: {                  // Nierozpoznane polecenie.
                Console::println(Message::MENU_wrongInput);
            }
        }
    }
}

void Controller::travellingSalesmanProblem() {
    Console::print(Message::FILE_getFilename);
    
    if (loadFile(Console::getInput())) {
        std::unique_ptr<LibraryObject> libraryObject(new LibraryObject(file));
        std::unique_ptr<DistanceMatrix> distanceMatrix(libraryObject->toDistanceMatrix());
        
        Console::println();
        Console::println(Message::SALESMAN_displayAllItems);
        Console::println(Message::SALESMAN_dynamicProgramming);
        Console::println();
        distanceMatrix->display();
        Console::println();

        std::chrono::high_resolution_clock::time_point startTime = std::chrono::high_resolution_clock::now();
            
        std::vector<int> result = TravellingSalesmanProblem::solveUsingDynamicProgramming(distanceMatrix.get());

        std::chrono::high_resolution_clock::time_point stopTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> spanTime = std::chrono::duration_cast<std::chrono::duration<double>>(stopTime - startTime);

        Console::displayResult(result);
        std::cout << "Time: " << spanTime.count() << "\n";
    }
}

bool Controller::loadFile(std::string filename) {
    file.open(filename);
    Console::println(file.isOpen() ? Message::FILE_loadSuccess : Message::FILE_loadFailure);
    return file.isOpen();
}
