//
// Created by mikko on 04.12.22.
//

#ifndef LAB2_LIST_H
#define LAB2_LIST_H
#pragma once
#include <iostream>
#include<string>
#include "Route.h"


template<class T>
class List{
private:
    int size;
    T* data;

public:
    List() : size(0), data(nullptr) {};
    List(const List<T>& myArray);
    ~List() {
        clear();
    }

    void clear();
    void sorting();
    [[nodiscard]] int getSize() const{
        return size;
    }
    T& operator[](int);
    List<T>& operator+=(const T& obj);
    List<T>& operator-=(const int index);
    List<T>& operator=(const List<T>& myArray);
};

template<class T>
List<T>::List(const List<T>& myArray) {
    data = new T[myArray.size];
    size = myArray.size;
    for (int i = 0; i < myArray.size; i++)
        data[i] = myArray.data[i];
}

template<class T>
T& List<T>::operator[](int index){
    std::string err = "Index " + std::to_string(index) + " does not exist";
    if (index < 0 || index >= size)
        throw err;
    return data[index];
}

template<class T>
List<T>& List<T>::operator+=(const T& obj) {
    T* tmp = data;
    size++;
    data = new T[size];
    for (int i = 0; i < size - 1; i++)
        data[i] = tmp[i];
    data[size - 1] = obj;
    return *this;
}

template<class T>
List<T>& List<T>::operator-=(const int index) {
    std::string err = "Index " + std::to_string(index) + " does not exist";
    if (index < 0 || index >= size)
        throw err;
    T* tmp = new T[size - 1];
    int k = 0;
    for (int i = 0; i < size; i++)
        if (i != index)
            tmp[k++] = data[i];
    size--;
    data = tmp;
    return *this;
}

template<class T>
List<T>& List<T>::operator=(const List<T>& myArray){
    if (this == &myArray)
        return *this;
    delete[] data;
    data = new T[myArray.size];
    size = myArray.size;
    for (int i = 0; i < myArray.size; i++)
        data[i] = myArray.data[i];
    return *this;
}


/*template<class T>
void List<T>::sorting() {
    List<T> routes;
    List<Route> r;
    for (int i = 1; i < size; i++)
        for (int j = 0; j < size - i; j++) {
        }
}*/

template<class T>
void List<T>::clear() {
    delete[] data;
    data = nullptr;
    size = 0;
}
#endif //LAB2_LIST_H
