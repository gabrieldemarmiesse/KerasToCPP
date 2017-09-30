//
// Created by smith on 9/29/2017.
//

#include "Conv2D.h"
#include <iostream>
#include <c++/cassert>

using namespace std;

void Conv2D::call(MultiDimArray *in, MultiDimArray *out) {

    for(int i=0; i<out->shape[0];i++){
        for(int j=0; j<out->shape[1];j++){
            for(int k=0; k<out->shape[2];k++){

                /* Now that we know where to put the value we will compute,
                we just have to iterate through the correct part of the kernel*/
                double sum = 0;
                for(int l=0; l<kernel.shape[0];l++){
                    for(int m=0; m<kernel.shape[2]; m++){
                        for(int n=0; n<kernel.shape[3];n++){
                            sum+= (*(in->get())) * (*(kernel.get(l,i,m,n)));
                        }
                    }
                }
                sum +=biases.values[i];
                *(out->get(i,j,k)) = sum;

            }
        }
    }
}

std::vector<int> Conv2D::getOutputShapeFor(std::vector<int> *inputShape) {
    assert(inputShape->size()==3);
    assert((*inputShape)[0]==kernel.shape[0]);
    assert(kernel.shape[1] == biases.shape[0]);
    assert(kernel.shape[2]%2 == 1); //works only with odd size kernels.
    assert(kernel.shape[3]%3 == 1); //works only with odd size kernels.


    int newHeight = (*inputShape)[1] - (kernel.shape[2]-1);
    int newWidth = (*inputShape)[2] - (kernel.shape[3]-1);

    return std::vector<int>({biases.shape[0],newHeight, newWidth});
}
