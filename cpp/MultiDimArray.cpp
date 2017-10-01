//
// Created by smith on 9/29/2017.
//
#include <vector>
#include <c++/cassert>
#include "MultiDimArray.h"
#include <c++/fstream>
#define CHECK_BOUNDS 0

MultiDimArray::MultiDimArray(std::vector<int> dims) {
    shape = dims;
    int totalSize=1;
    for(auto dim : dims)
        totalSize*=dim;

    values.resize(static_cast<unsigned long long int>(totalSize));
    for (float & value : values)
        value = 0;

}

void MultiDimArray::fillArray(std::ifstream *file) {

    unsigned long long toRead = values.size() * sizeof(float);
    file->read((char *) values.data(), toRead);
}

float* MultiDimArray::get(int dim0) {
    #if (CHECK_BOUNDS)
    checkBounds({dim0});
    #endif
    return &(values[dim0]);
}

float* MultiDimArray::get(int dim0, int dim1) {
    #if (CHECK_BOUNDS)
    checkBounds({dim0, dim1});
    #endif
    return &(values[dim0*shape[1] + dim1]);
}

float* MultiDimArray::get(int dim0, int dim1, int dim2) {
    #if (CHECK_BOUNDS)
    checkBounds({dim0, dim1, dim2});
    #endif
    return &(values[dim2 + shape[2]*(dim1 + shape[1]*dim0)]);
}

float* MultiDimArray::get(int dim0, int dim1, int dim2, int dim3) {
    #if (CHECK_BOUNDS)
    checkBounds({dim0, dim1, dim2, dim3});
    #endif
    return &(values[dim3 + shape[3]*(dim2 + shape[2]*(dim1 + shape[1]*dim0))]);
}

void MultiDimArray::checkBounds(const std::vector<int> &dims) {

    assert(dims.size()!=shape.size());
    for(int i=0; i<dims.size(); i++){
        assert(dims[i]>=shape[i]);
    }
}

