//
// Created by smith on 9/29/2017.
//

#ifndef CPP_ACTIVATION_H
#define CPP_ACTIVATION_H


#include "../Layer.h"
#include "../MultiDimArray.h"

class Activation : public Layer{

    /* Since an activation function doesn't change
     the shape of an array, we don't need to allocate
     new space in memory (this is also because we only
     work with keras senquential models)*/

    public:

    explicit Activation(std::string str);
    void call(MultiDimArray *in, MultiDimArray *out) override;
    std::vector<int> getOutputShapeFor(std::vector<int>* inputShape) override;
    std::string act;
};


#endif //CPP_ACTIVATION_H
