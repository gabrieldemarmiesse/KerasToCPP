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
    std::vector<double> values;
    std::vector<int> shape;
    double* get(int dim0);
    double* get(int dim0, int dim1);
    double* get(int dim0, int dim1, int dim2);
    double* get(int dim0, int dim1, int dim2, int dim3);
};


#endif //CPP_MULTIDIMARRAY_H
