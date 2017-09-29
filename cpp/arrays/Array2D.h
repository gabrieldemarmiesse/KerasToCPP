//
// Created by smith on 9/29/2017.
//

#ifndef CPP_ARRAY2D_H
#define CPP_ARRAY2D_H


#include <mshtmlc.h>
#include "../MultiDimArray.h"

class Array2D : public MultiDimArray{

public:
    explicit Array2D(int dim0, int dim1, bool init=true);
    int shape[2];
    double access(int dim0, int dim1);
};


#endif //CPP_ARRAY2D_H
