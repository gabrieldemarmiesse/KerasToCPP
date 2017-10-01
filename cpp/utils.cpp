//
// Created by smith on 9/30/2017.
//

#include <iostream>
#include <vector>
#include <c++/fstream>
#include <c++/cassert>
#include "utils.h"

std::string getActivation(std::ifstream *file){
    unsigned int flag;
    file->read((char *) &flag,sizeof(unsigned int));
    switch(flag){
        case 1:
            return "linear";
        case 2:
            return "relu";
        case 3:
            return "softmax";
        default:
            throw "incorrect flag";
    }
}