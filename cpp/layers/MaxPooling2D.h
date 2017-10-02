//
// Created by smith on 9/29/2017.
//

#ifndef CPP_MAXPOOLING2D_H
#define CPP_MAXPOOLING2D_H


#include "../Layer.h"

class MaxPooling2D : public Layer{
public:
    explicit MaxPooling2D(std::ifstream *file);
    void call(const MultiDimArray &in, MultiDimArray &out) override;
    std::vector<int> getOutputShapeFor(std::vector<int>* inputShape) override;

private:
    int poolSizeH;
    int poolSizeW;
};


#endif //CPP_MAXPOOLING2D_H
