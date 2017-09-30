//
// Created by smith on 9/29/2017.
//

#ifndef CPP_ACTIVATION_H
#define CPP_ACTIVATION_H


#include "../Layer.h"
#include "../MultiDimArray.h"

class Activation : public Layer{

    public:
    explicit Activation(std::ifstream *file);
    explicit Activation(std::string str);
    void call(MultiDimArray *in, MultiDimArray *out) override;
    std::vector<int> getOutputShapeFor(std::vector<int>* inputShape) override;
    std::string act;
};


#endif //CPP_ACTIVATION_H
