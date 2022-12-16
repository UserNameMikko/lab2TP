//
// Created by mikko on 04.12.22.
//
#include <fstream>
#include <utility>
#include <string>
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
    getchar();
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