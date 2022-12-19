#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "List.h"

int secondProgram() {
    // Open the file for reading
    std::ifstream input_file("in.txt");

    // Check if the file was successfully opened
    if (!input_file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    // Read each word from the file
    std::string word;
    int ch;
    do {
        std::cout << "1 - to process file contents" << std::endl;
        std::cout << "2 - file contents without processing" << std::endl;
        std::cout << "0 - exit" << std::endl;
        std::cin >> ch;
        switch (ch) {
            case 1:
                while (input_file >> word) {
                    // Check if the first and last letter of the word are vowels
                    if (word.front() == 'a' || word.front() == 'e' || word.front() == 'i' ||
                        word.front() == 'o' || word.front() == 'u' || word.front() == 'A' ||
                        word.front() == 'E' || word.front() == 'I' || word.front() == 'O' ||
                        word.front() == 'U' || word.front() == 'Y' || word.front() == 'y') {
                        if (word.back() == 'a' || word.back() == 'e' || word.back() == 'i' ||
                            word.back() == 'o' || word.back() == 'u' || word.back() == 'A' ||
                            word.back() == 'E' || word.back() == 'I' || word.back() == 'O' ||
                            word.back() == 'U' || word.back() == 'Y' || word.back() == 'y') {
                            // If the first and last letter are both vowels, display the word
                            std::cout << word << std::endl;
                        }
                    }
                }
                break;
            case 2:
                while (input_file >> word) {
                    std::cout << word << std::endl;
                }
                break;
            case 0:
                std::cout << "program ended by user" << std::endl;
                break;
            default:
                std::cout << "incorrect choice" << std::endl;
        }
    } while (ch != 0);

    return 0;
}
