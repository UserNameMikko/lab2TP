//
// Created by mikko on 04.12.22.
//
#include <fstream>
#include <utility>
#include "helper.h"
#include "Route.h"

Route::Route() {
    this->startOfRoute=" ";
    this->endOfRoute=" ";
    this->numOfRoute = 0;
}
Route::Route(std::string start, std::string end, int num) {
    this->startOfRoute = std::move(start);
    this->endOfRoute = std::move(end);
    this->numOfRoute = num;
}
Route::Route(Route &route) {
    this->startOfRoute = route.startOfRoute;
    this->endOfRoute = route.endOfRoute;
    this->numOfRoute = route.numOfRoute;
}
Route::~Route() = default;

void Route::setStartDestination(std::string start){
    this->startOfRoute = std::move(start);
}
void Route::setEndDestination(std::string end) {
    this->endOfRoute = std::move(end);
}
void Route::setNumOfRoute(int n) {
    this->numOfRoute = n;
}

std::string Route::getStartDestination() {
    return this->startOfRoute;
}
std::string Route::getEndDestination() {
    return this->endOfRoute;
}
int Route::getNumOfRoute() const{
    return this->numOfRoute;
}

void Route::inputFromConsole(){
    std::cout << "input the start of route:" << std::endl;
    getchar();
    getline(std::cin, startOfRoute);
    //std::cin >> startOfRoute;
    std::cout << "input the end of route:" << std::endl;
    //std::cin >> endOfRoute;
    getline(std::cin, endOfRoute);
    std::cout << "input the number of route:" << std::endl;
    std::cin >> numOfRoute;

}

void Route::change() {
    std::cout << "input the start:" << std::endl;
    //getchar();
    getline(std::cin, startOfRoute);
    std::cout << "input the end:" << std::endl;
    getline(std::cin, endOfRoute);
    std::cout << "input num: " << std::endl;
    std::cin >> numOfRoute;
}

bool Route::operator > (Route& route) const {
    return numOfRoute > route.numOfRoute;
}
bool Route::operator < (Route &route) const {
    return numOfRoute < route.numOfRoute;
}

/*
void Route::show() {
    std::cout << *this << std::endl;
}*//*
void Route::saving() {
    std::ofstream file_out;
    std::string init_file = "data.txt";
    file_out.open(init_file, std::ios_base::app);
    if (!file_out)
        throw "Error opening!";
    else {
        file_out << std::endl << startOfRoute << std::endl << endOfRoute << std::endl
                 << numOfRoute << std::endl;
        file_out.close();
    }
}
void Route::rewrite() {
    std::cout << "-------------------------------" << std::endl;
    std::cout << "Change data of Route\n"
                 "input:\n"
                 "start of route-> end of route -> num of route"<<std::endl<<
              "if your text variables contains >1 word use '_' for current work of program"<< std::endl;
    std::cin>>this->startOfRoute>>this->endOfRoute>>this->numOfRoute;
}

void Route::redact(std::string start, std::string end, int num) {
    this->startOfRoute = std::move(start);
    this->endOfRoute = std::move(end);
    this->numOfRoute = num;
}

*/