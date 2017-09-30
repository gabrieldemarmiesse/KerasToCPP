//
// Created by smith on 9/29/2017.
//

#include "Flatten.h"

void Flatten::call(MultiDimArray *in, MultiDimArray *out) {

    for(int i=0; i<in->values.size();i++){
        out->values[i] = in->values[i];
    }
}

std::vector<int> Flatten::getOutputShapeFor(std::vector<int> *inputShape) {
    int totalSize = 1;
    for(auto value: *inputShape)
        totalSize*=value;
    return std::vector<int>({totalSize});
}
