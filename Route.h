//
// Created by mikko on 04.12.22.
//
#pragma once
#include <iostream>
#include <utility>
#ifndef LAB2_ROUTE_H
#define LAB2_ROUTE_H
class Route {
private:
    std::string startOfRoute;
    std::string endOfRoute;
    int numOfRoute;
public:

    Route();
    Route(std::string start, std::string end, int num);
    Route(Route &route);
    ~Route();
    void setStartDestination(std::string start);
    void setEndDestination(std::string end);
    void setNumOfRoute(int n);

    std::string getStartDestination();
    std::string getEndDestination();
    [[nodiscard]] int getNumOfRoute()const;

    void inputFromConsole();
    void change();

    friend std::ostream& operator<<(std::ostream& os, Route& obj) {
            os <<"Start: "<< obj.getStartDestination() <<std::endl<<
            "End: " <<obj.getEndDestination() <<std::endl <<
            "Number: " << obj.getNumOfRoute()  << std::endl;
        return os;
    }
    bool operator > (Route& route) const;
    bool operator < (Route &route) const;
};

typedef struct Instance {
    Route* data;
    Instance* next;
} Instance;
#endif //LAB2_ROUTE_H
