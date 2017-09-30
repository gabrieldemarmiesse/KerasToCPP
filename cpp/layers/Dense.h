//
// Created by smith on 9/29/2017.
//

#ifndef CPP_DENSE_H
#define CPP_DENSE_H


#include "../Layer.h"

class Dense : public Layer{

    void call(MultiDimArray *in, MultiDimArray *out) override;
    std::vector<int> getOutputShapeFor(std::vector<int>* inputShape) override;
    MultiDimArray kernel; //should be 2D
    MultiDimArray biases; //should be 1D
};


#endif //CPP_DENSE_H
