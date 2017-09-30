//
// Created by smith on 9/30/2017.
//

#include <iostream>
#include <vector>
#include <c++/fstream>
#include <c++/cassert>

using namespace std;

template <class myType>
void fillArray(ifstream *file, vector<myType>* pointer){

    unsigned long long toRead = pointer->size() * sizeof(myType);
    file->read((char *) &(pointer->data()), toRead);
}

string getActivation(ifstream *file){
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
            assert(false);
    }
}