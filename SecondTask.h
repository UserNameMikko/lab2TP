#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "List.h"
bool check(const std::string& inp) {
/**
   a',
    'o',
   'e',
     'i',
     'y',
    'u',
   'A',
   'O',
    'E',
   'I',
     'Y',
   'U'
*/

    List<int> listOfStartIndex; // start index of symbols in string
    List<int> listOfEndIndex;  // end index of symbols in string
    std::string newString;
    int startWordIndex = -1; // the first letter of the word
    int endWordIndex = -1; // the last letter of the word
    //check one line in file
    for (int i = 0; i < inp.size(); ++i) {  //current string searching for start index
        // if we met space symbol we need to check the first and the last letter of this word
        if (i == 0 || inp[i - 1] == ' ') {
            if (inp[i] == 'a' || inp[i] == 'o' || inp[i] == 'e' ||
                inp[i] == 'i' || inp[i] == 'y' || inp[i] == 'u') {
                startWordIndex = i;
                listOfStartIndex += startWordIndex;
            }
        }
    }
    for (int i = 0; i < inp.size(); ++i) {  //current string searching for end index
        // if we met space symbol we need to check the first and the last letter of this word
        if ((inp[i] == ' ' ||inp[i] == '\n')) {
            if (inp[i - 1] == 'a' || inp[i - 1] == 'o' || inp[i - 1] == 'e' ||
                inp[i - 1] == 'i' || inp[i - 1] == 'y' || inp[i - 1] == 'u') {
                endWordIndex = i - 1;
                listOfEndIndex += endWordIndex;
            }
        }
    }
    std::cout << "startWordIndex: " << startWordIndex << std::endl
              << "endWordIndex: " << endWordIndex << std::endl
              <<"string size: "<<inp.size() << std::endl
              << "string: " << inp <<std::endl
              <<" list start size: " << listOfStartIndex.getSize()<<std::endl
              << " list end size: " << listOfEndIndex.getSize()<<std::endl
              << std::endl << std::endl;

    for (int i = 0; i < listOfStartIndex.getSize(); ++i) {
        std::cout << "startWordIndex #" << i << ":" << listOfStartIndex[i] << std::endl;

    }
    for (int i = 0; i < listOfEndIndex.getSize(); ++i) {
        std::cout << "endWordIndex #" << i << ":" << listOfEndIndex[i] << std::endl << std::endl;
    }
    for (int listIndex = 0; listIndex < listOfStartIndex.getSize(); ++listIndex) {
        if (listOfStartIndex.getSize() == listOfEndIndex.getSize()) {
            for (int j = listOfStartIndex[listIndex]; j <= listOfEndIndex[listIndex];j++){
                newString+=inp[j];
            }
            newString += ' ';
            std::cout << "new string: " <<newString << std::endl;
        }

    }
    if (listOfStartIndex.getSize() == listOfEndIndex.getSize())
        return true;
    else return false;

}

void secondProgram() {
    std::ifstream in("in.txt");
    int c;
    std::string line;
    std::stringstream ss;
    do {
        std::cout << "1 - to process file contents" << std::endl;
        std::cout << "2 - file contents without processing" << std::endl;
        std::cout << "0 - exit" << std::endl;
        std::cin >> c;
        switch (c) {
            case 1:
                try{
                    if (in.is_open()){
                        while (getline(in, line)) {
                            if (check(line)) {
                                //ss << line << '\n';
                                getline(in, line);
                            }
                        }
                    }
                    else throw std::exception("something went wrong!");
                    std::cout << ss.str();
                }
                catch (std::exception& err){
                    std::cerr << err.what() << std::endl;
                }

                break;
            case 2:
                try{
                    if (in.is_open())
                        while (getline(in, line))
                            ss << line << '\n';
                    else throw std::exception("something went wrong!");
                    std::cout << ss.str();
                } catch (const std::exception& err){
                    std::cerr << err.what() << std::endl;
                }
                break;
            case 0:
                std::cout << "program finished by user" << std::endl;
                break;
            default:
                std::cout << "incorrect function" << std::endl;
                break;
        }
    } while (c != 0);
    in.close();
}
