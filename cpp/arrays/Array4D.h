//
// Created by smith on 9/29/2017.
//

#ifndef CPP_ARRAY4D_H
#define CPP_ARRAY4D_H

#include "../MultiDimArray.h"

class Array4D : public MultiDimArray{
    public:
    explicit Array4D(int dim0, int dim1, int dim2, int dim3, bool init=true);
    int shape[1];
    double access(int dim0, int dim1, int dim2, int dim3);
};


#endif //CPP_ARRAY4D_H
