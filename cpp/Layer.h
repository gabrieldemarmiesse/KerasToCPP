//
// Created by smith on 9/29/2017.
//

#ifndef CPP_LAYER_H
#define CPP_LAYER_H

#include <iostream>
#include <c++/memory>
#include "MultiDimArray.h"


class Layer {

    public:
    virtual void call(MultiDimArray *in, MultiDimArray *out) = 0;
    virtual std::vector<int> getOutputShapeFor(std::vector<int>* inputShape) = 0;

};


#endif //CPP_LAYER_H
