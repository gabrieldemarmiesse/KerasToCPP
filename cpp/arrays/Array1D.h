//
// Created by smith on 9/29/2017.
//

#ifndef CPP_ARRAY1D_H
#define CPP_ARRAY1D_H

#include "../MultiDimArray.h"

class Array1D : public MultiDimArray{
    public:
    explicit Array1D(int dim0, bool init=true);
    int shape[1];
    double access(int dim0);
};


#endif //CPP_ARRAY1D_H
