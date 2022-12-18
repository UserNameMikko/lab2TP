#include "FirstTask.h"
#include "SecondTask.h"
int main() {

    std::cout << "select a type of program:" << std::endl
    << "1 - The first task" << std::endl
    << "2 - The second task" << std::endl
    << "0 - Exit from program" << std::endl;
    int ch;
    std::cin >> ch;
    switch (ch) {
        case 1:
            firstProgram();
            break;
        case 2:
            secondProgram();
            break;
        case 0:
            std::cout << "Program finished by user" << std::endl;
        default:
            break;
    }
    return 0;
}