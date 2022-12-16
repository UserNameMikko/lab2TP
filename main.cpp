#include "List.h"
#include "Route.h"
#include "helper.h"
#include <fstream>

void print (List<Route>&routes){
    for (int i = 0; i < routes.getSize();i++){
        std::cout<<routes[i];
    }
}
void addObject(List<Route>& routes) {
    Route route;
    route.inputFromConsole();
    routes += route;
    //routes.sorting();
}

void changeObject(List<Route>& routes) {
    if (routes.getSize() > 0) {
        print(routes);
        std::cout << "input the index of objects which will be changed:" << std::endl;
        routes[safeInput(1, routes.getSize()) - 1].change();
    }
    else
        std::cout << "list is empty";
    //routes.sorting();
}

void deleteObject(List<Route>& routes) {
    if (routes.getSize() > 0) {

        print(routes);
        std::cout << "input the index of object which will be deleted:" << std::endl;
        routes -= safeInput(1, routes.getSize()) - 1;
    }
    else
        std::cout << "list is empty";
    //routes.sorting();
}
void deleteAll(List<Route>& routes) {
    if (routes.getSize() > 0) {
        routes.clear();
        std::cout << "list erased" << std::endl;
    }
    else
        std::cout << "list is empty" << std::endl;
    //5routes.sorting();
}

void printLast(List<Route>& routes) {
    if (routes.getSize() == 0)
        std::cout << "list is empty" << std::endl;
    else {
        std::cout << "last element:";
        std::cout<<routes[routes.getSize() - 1];
    }
}

void searchObjects(List<Route>& routes) {
    if (routes.getSize() == 0)
        std::cout << "list is empty\n";
    else {
        bool isPrint = false;
        std::string routeName;
        std::cout << "input start, end or number of route:" << std::endl;
        getchar();
        std::cin >> routeName;
        for (int i = 0; i < routes.getSize(); i++)
            if (routes[i].getStartDestination() == routeName || routes[i].getEndDestination() == routeName
            || std::to_string(routes[i].getNumOfRoute()) == routeName){
                isPrint = true;
                std::cout << "Search result:" << std::endl << std::endl << routes[i] << std::endl;
            }
        if (!isPrint)
            std::cout << "Nothing found" << std::endl;
    }
}
int firstProgramMenu() {
    int ch;
    try {
        std::cout
        << "1 - add objects to list" << std::endl
        << "2 - change objects in list" << std::endl
        << "3 - delete object from list" << std::endl
        << "4 - erase all objects from list" << std::endl
        << "5 - output of last element of list" << std::endl
        << "6 - search object in list by all fields" << std::endl
        << "7 - print all elements of list" << std::endl
        << "8 - exit" << std::endl;
        std::cin >> ch;
        if (ch > 0 && ch < 9)
            return ch;
        else
            throw "incorrect input";
    } catch (...) {
        std::cout << "incorrect input" << std::endl;
    }

}

// here is process of working of the first program
void firstProgram() {
    List<Route> list;
    Route r;
    int ch;
    do {
        ch = firstProgramMenu();
        switch (ch) {
            case 1:
                addObject(list);
                break;
            case 2:
                changeObject(list);
                break;
            case 3:
                deleteObject(list);
                break;
            case 4:
                deleteAll(list);
                break;
            case 5:
                printLast(list);
                break;
            case 6:
                searchObjects(list);
                break;
            case 7:
                if (list.getSize() == 0)
                    std::cout << "list is empty";
                else
                    for (int i = 0; i < list.getSize(); ++i) {
                        std::cout << list[i] << std::endl;
                    }
                break;
            case 8:
                std::cout << "exit from the first program by user" << std::endl;
                break;
            default:
                break;
        }
    } while (ch != 8);

}
void secondProgram() {
    std::cout<< "empty";
}




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