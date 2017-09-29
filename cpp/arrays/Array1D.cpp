//
// Created by smith on 9/29/2017.
//

#include "Array1D.h"

Array1D::Array1D(int dim0, bool init) {
    shape[0] = dim0;
    nbDims = 1;
    initSize(shape);
    initialize(init);
}

double Array1D::access(int dim0) {
    return values[dim0];
}


