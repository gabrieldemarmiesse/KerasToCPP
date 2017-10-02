//
// Created by smith on 9/29/2017.
//

#ifndef CPP_FLATTEN_H
#define CPP_FLATTEN_H


#include "../Layer.h"

class Flatten : public Layer{

public:
    void call(const MultiDimArray &in, MultiDimArray &out) override;
    std::vector<int> getOutputShapeFor(std::vector<int>* inputShape) override;

};


#endif //CPP_FLATTEN_H
