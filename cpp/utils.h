//
// Created by smith on 9/30/2017.
//

#ifndef CPP_UTILS_H_H
#define CPP_UTILS_H_H
#include <iostream>

template <class myType>
void fillArray(std::ifstream *file, std::vector<myType>* pointer);

std::string getActivation(std::ifstream *file);
#endif //CPP_UTILS_H_H
