//
// Created by smith on 9/29/2017.
//
#include <vector>
#include "MultiDimArray.h"
#define CHECK_BOUNDS 1

MultiDimArray::MultiDimArray(std::vector<int> dims) {
    shape = dims;
    int totalSize=1;
    for(auto dim : dims)
        totalSize*=dim;

    values.resize(static_cast<unsigned long long int>(totalSize));
    for (float & value : values)
        value = 0;
    //std::cout << "initialized array" << std::endl;

}

float* MultiDimArray::get(int dim0) {
    return &(values[dim0]);
}

float* MultiDimArray::get(int dim0, int dim1) {
    #if defined(CHECK_BOUNDS)
    if(dim0>=shape[0] || dim1>=shape[1])
        throw std::invalid_argument("MyFunc argument too large.");
    #endif
    return &(values[dim0*shape[1] + dim1]);
}

float* MultiDimArray::get(int dim0, int dim1, int dim2) {
    #if defined(CHECK_BOUNDS)
    if(dim0>=shape[0] || dim1>=shape[1]  || dim2>=shape[2])
        throw std::invalid_argument("MyFunc argument too large.");
    #endif
    return &(values[dim2 + shape[2]*(dim1 + shape[1]*dim0)]);
}

float* MultiDimArray::get(int dim0, int dim1, int dim2, int dim3) {
    dim0 = shape[0]-1-dim0;
    dim1 = shape[1]-1-dim1;
    #if defined(CHECK_BOUNDS)
    if(dim0>=shape[0] || dim1>=shape[1] || dim2>=shape[2] || dim3>=shape[3])
        throw std::invalid_argument("MyFunc argument too large.");
    #endif
    return &(values[dim3 + shape[3]*(dim2 + shape[2]*(dim1 + shape[1]*dim0))]);
}
