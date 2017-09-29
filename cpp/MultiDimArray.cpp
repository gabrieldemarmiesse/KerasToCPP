//
// Created by smith on 9/29/2017.
//

#include "MultiDimArray.h"

void MultiDimArray::initialize() {
    for(int i = 0; i<size; i++)
        values[i] = 0;
}

void MultiDimArray::initSize(const int *shape) {
    size = 0;
    for(int i=0; i<nbDims; i++)
        size *=shape[i];
}
