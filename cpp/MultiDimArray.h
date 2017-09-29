//
// Created by smith on 9/29/2017.
//

#ifndef CPP_MULTIDIMARRAY_H
#define CPP_MULTIDIMARRAY_H

#include <iostream>
#include <vector>

class MultiDimArray {

    public:
    int nbDims;
    int size;
    std::vector<double> values;

    protected:
    void initialize(bool init);
    void initSize(const int *shape);

};


#endif //CPP_MULTIDIMARRAY_H
