//
// Created by smith on 9/29/2017.
//

#ifndef CPP_ARRAY3D_H
#define CPP_ARRAY3D_H


#include "../MultiDimArray.h"

class Array3D : public MultiDimArray {
    public:
    explicit Array3D(int dim0, int dim1, int dim2, bool init=true);
    int shape[1];
    double access(int dim0, int dim1, int dim2);
};


#endif //CPP_ARRAY3D_H
