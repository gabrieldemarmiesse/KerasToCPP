//
// Created by smith on 9/29/2017.
//

#include <iostream>
#include <cassert>
#include <c++/limits>
#include "MaxPooling2D.h"
using namespace std;

void MaxPooling2D::call(MultiDimArray *in, MultiDimArray *out) {

    for(int i=0; i<out->shape[0]; i++){
        for(int j=0; j<out->shape[1]; i++){
            for(int k=0; k<out->shape[2];i++){

                double maximum = std::numeric_limits<double>::min();

                for(int l=0; l<poolSizeH; l++){
                    for(int m=0; m<poolSizeW; m++){
                        maximum = max(maximum, *(in->get(i, j*poolSizeH + l,k*poolSizeW + m)));
                    }
                }
                *(out->get(i,j,k)) = maximum;
            }
        }
    }
}

std::vector<int> MaxPooling2D::getOutputShapeFor(std::vector<int> *inputShape) {
    assert(inputShape->size()==3);
    assert((*inputShape)[1]%poolSizeH==0);
    assert((*inputShape)[2]%poolSizeW==0);

    std::vector<int> result;
    result.resize(3);
    result[0] = (*inputShape)[0];
    result[1] = (*inputShape)[1]/poolSizeH;
    result[2] = (*inputShape)[2]/poolSizeW;
    return result;
}
