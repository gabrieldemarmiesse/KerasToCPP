//
// Created by smith on 9/29/2017.
//

#include <c++/cassert>
#include <iostream>
#include "Dense.h"
using namespace std;

void Dense::call(MultiDimArray *in, MultiDimArray *out) {

    for(int i=0; i<biases.shape[0];i++){
        double sum=0;

        for(int j=0; j<in->shape[0];i++)
            sum+= in->values[j] * (*kernel.get(i,j));

        sum+=biases.values[i];
        out->values[i]=sum;
    }

}

std::vector<int> Dense::getOutputShapeFor(std::vector<int> *inputShape) {
    assert(inputShape->size()==1);
    assert((*inputShape)[0] == kernel.shape[0]);
    assert( biases.shape[0] == kernel.shape[1]);

    return std::vector<int>({biases.shape[0]});
}
