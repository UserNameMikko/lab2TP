//
// Created by mikko on 04.12.22.
//
/*
#ifndef LAB2_KEEPER_H
#define LAB2_KEEPER_H
#pragma once
#include "Route.h"
class Keeper{
private:
    int size;
    Instance * head = nullptr;
public:
    Keeper();
    Keeper(int size);
    ~Keeper();
    int get_size();
    Route* operator[] (const int index);

    void insert(Route* n_data);
    void remove(int index);
    void save();
    void load();
};
#endif //LAB2_KEEPER_H
*/