//
// Created by smith on 9/29/2017.
//

#ifndef CPP_DENSE_H
#define CPP_DENSE_H


#include "../Layer.h"

class Dense : public Layer{

public:
    explicit Dense(std::ifstream *file);
    void call(const MultiDimArray &in, MultiDimArray &out) override;
    std::vector<int> getOutputShapeFor(std::vector<int>* inputShape) override;

private:
    std::shared_ptr<MultiDimArray> kernel; //should be 2D
    std::shared_ptr<MultiDimArray> biases; //should be 1D
    std::string activation;
};


#endif //CPP_DENSE_H
