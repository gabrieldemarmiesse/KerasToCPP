//
// Created by smith on 9/29/2017.
//
#include <vector>
#include "MultiDimArray.h"


MultiDimArray::MultiDimArray(std::vector<int> dims) {
    shape = dims;
    int totalSize=1;
    for(auto dim : dims)
        totalSize*=dim;

    values.resize(static_cast<unsigned long long int>(totalSize));
    for (double & value : values)
        value = 0;
    std::cout << "initialized array" << std::endl;

}

double* MultiDimArray::get(int dim0) {
    return &(values[dim0]);
}

double* MultiDimArray::get(int dim0, int dim1) {
    return &(values[dim0*shape[1] + dim1]);
}

double* MultiDimArray::get(int dim0, int dim1, int dim2) {
    return &(values[dim2 + shape[2]*(dim1 + shape[1]*dim0)]);
}

double* MultiDimArray::get(int dim0, int dim1, int dim2, int dim3) {
    return &(values[dim3 + shape[3]*(dim2 + shape[2]*(dim1 + shape[1]*dim0))]);
}
