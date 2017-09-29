//
// Created by smith on 9/29/2017.
//

#include "Array3D.h"

Array3D::Array3D(int dim0, int dim1, int dim2, bool init) {
    shape[0] = dim0;
    shape[1] = dim1;
    shape[2] = dim2;
    nbDims = 3;
    initSize(shape);
    initialize(init);
}

double Array3D::access(int dim0, int dim1, int dim2) {
    return values[dim2 + shape[2]*(dim1 + shape[1]*dim0)];
}