//
// Created by smith on 9/29/2017.
//

#include "Array2D.h"

Array2D::Array2D(int dim0, int dim1, bool init) {
    shape[0] = dim0;
    shape[1] = dim1;
    nbDims = 2;
    initSize(shape);
    initialize(init);
}

double Array2D::access(int dim0, int dim1) {
    return values[dim0*shape[1] + dim1];
}
