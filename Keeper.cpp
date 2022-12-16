//
// Created by mikko on 04.12.22.
//
/*
#include <fstream>
#include "Keeper.h"

Keeper::Keeper() {
    size = 0;
    head = nullptr;
}
Keeper::Keeper(int size): head(nullptr) {
    this->size = size;
}
Keeper::~Keeper() {
    if(head != nullptr) {
        Instance* buff;
        while (head->next != nullptr) {
            buff = head;
            head = head->next;
            buff->data->~Route();
            delete(buff);
        }
    }

}
Route* Keeper::operator[] (const int index) {
    if ((index >= size) || (index < 0))
        throw "Incorrect index!";
    else {
        Instance * buffer = head;
        for (int i = 0; i < size-index-1 ; i++)
            buffer = buffer->next;
        return (buffer->data);
    }
}

int Keeper::get_size() {
    return size;
}

void Keeper::insert(Route *_data) {
    Instance* tmp;
    tmp = new Instance;
    tmp->data = _data;
    if(size == 0)
        tmp->next = 0;
    else
        tmp->next = head;
    ++size;
    head = tmp;
}

void Keeper::load() {
    if (size != 0) {
        Instance * buffer;
        while (head->next != nullptr)
        {
            buffer = head;
            head = head->next;
            buffer->data->~Route();
            delete(head);
        }
        head->data->~Route();
        delete(head);
    }
    std::ifstream file_in;
    std::string init_file = "data.txt";
    Route* routes;
    std::string start, end;
    int numOfRoutes, routes_count;
    file_in.open(init_file);
    if (!file_in)
        throw "no file";
    file_in >> routes_count;

    for (int i = 0; i < routes_count; i++) {
        file_in >> start >> end >> numOfRoutes;
        Route* route;
        route = new Route;
        route->setStartDestination(start);
        route->setEndDestination(end);
        route->setNumOfRoute(numOfRoutes);
        routes= route;
        insert(routes);
        file_in.ignore(32767, '\n');
    }
}

void Keeper::remove(int index) {
    if(size == 0)
        throw "size == 0!";
    int c = 0;
    while (c < index-1) {
        head = head->next;
        c++;
    }
    Instance * prev = head;
    prev->next->data->~Route();
    prev->next->next;
    delete(prev->next);
    --size;
}

void Keeper::save() {
    std::ofstream file_out;
    std::string init_file = "data.txt";
    file_out.open(init_file, std::ios_base::app);
    if (!file_out)
        throw "no such file or directory!";
    else {
        file_out << size << std::endl;
        file_out.close();
    }
    Instance* buf = head;
    for (int i = 0; i < size; i++) {
        buf->data->saving();
        buf = buf->next;
    }
}*/