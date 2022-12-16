//
// Created by mikko on 05.12.22.
//

#ifndef LAB2_HELPER_H
#define LAB2_HELPER_H
#include<iostream>
#include<string>
template <typename T>
T safeInput(T minInput, T maxInput) {
    while (true) {
        T method;
        std::cin >> method;
        if (std::cin.fail() || method < minInput || method > maxInput) {
            std::cin.clear();
            std::cout << "Íåâåðíûé ââîä.\nÏîâòîðèòå ñíîâà: ";
        } else {
            std::cin.ignore(32767, '\n');
            std::cin.clear();
            return method;
        }
        std::cin.ignore(32767, '\n');
    }
}
#endif //LAB2_HELPER_H
