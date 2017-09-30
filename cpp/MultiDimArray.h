//
// Created by smith on 9/29/2017.
//

#ifndef CPP_MULTIDIMARRAY_H
#define CPP_MULTIDIMARRAY_H

#include <iostream>
#include <vector>

class MultiDimArray {

    // Custom c++ version of a numpy array.
    public:

    explicit MultiDimArray(std::vector<int> dims);
    std::vector<float> values;
    std::vector<int> shape;
    float* get(int dim0);
    float* get(int dim0, int dim1);
    float* get(int dim0, int dim1, int dim2);
    float* get(int dim0, int dim1, int dim2, int dim3);
};


#endif //CPP_MULTIDIMARRAY_H
