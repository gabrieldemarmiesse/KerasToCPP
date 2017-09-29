//
// Created by smith on 9/29/2017.
//

#include "Array4D.h"

Array4D::Array4D(int dim0, int dim1, int dim2, int dim3, bool init) {
    shape[0] = dim0;
    shape[1] = dim1;
    shape[2] = dim2;
    shape[3] = dim3;
    nbDims = 4;
    initSize(shape);
    initialize(init);
}

double Array4D::access(int dim0, int dim1, int dim2, int dim3) {
    return values[dim3 + shape[3]*(dim2 + shape[2]*(dim1 + shape[1]*dim0))];
}