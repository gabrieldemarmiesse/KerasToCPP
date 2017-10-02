//
// Created by smith on 9/29/2017.
//

#ifndef CPP_CONV2D_H
#define CPP_CONV2D_H


#include "../Layer.h"

class Conv2D : public Layer{

public:
    explicit Conv2D(std::ifstream* file);
    void call(const MultiDimArray& in, MultiDimArray& out) override;
    std::vector<int> getOutputShapeFor(std::vector<int>* inputShape) override;

private:
    std::shared_ptr<MultiDimArray> kernel; //should be 2D
    std::shared_ptr<MultiDimArray> biases; //should be 1D
    std::string activation;
};


#endif //CPP_CONV2D_H
