//
// Created by smith on 9/29/2017.
//

#include "Conv2D.h"
#include "Activation.h"
#include <iostream>
#include <c++/fstream>
#include <c++/cassert>
#include "../utils.h"
#include <bitset>
using namespace std;

template<typename T>
void show_binrep(const T& a)
{
    const char* beg = reinterpret_cast<const char*>(&a);
    const char* end = beg + sizeof(a);
    while(beg != end)
        std::cout << std::bitset<CHAR_BIT>(*beg++) << ' ';
    std::cout << '\n';
}

Conv2D::Conv2D(ifstream *file) {
    unsigned int tmp;
    file->read((char *)&tmp, sizeof(unsigned int));
    int kernelDim0 = tmp;
    file->read((char *)&tmp, sizeof(unsigned int));
    int kernelDim1 = tmp;
    file->read((char *)&tmp, sizeof(unsigned int));
    int kernelDim2 = tmp;
    file->read((char *)&tmp, sizeof(unsigned int));
    int kernelDim3 = tmp;
    file->read((char *)&tmp, sizeof(unsigned int));
    int biasDim0 = tmp;
    kernel.reset(new MultiDimArray({kernelDim0, kernelDim1, kernelDim2, kernelDim3}));
    biases.reset(new MultiDimArray({biasDim0}));

    /*float toTest;
    //fread((void *)&toTest, sizeof(float), 1,file);
    bool a =file->read((char *)&toTest, sizeof(float)).gcount()==sizeof(toTest);
    cout << toTest<<endl;
    cout << a << endl;
    show_binrep(toTest);*/

    //Now we fill the weights.
    //fillArray<float>(file, &(kernel->values));
    unsigned long long toRead = kernel->values.size() * sizeof(float);
    file->read((char *) kernel->values.data(), toRead);
    cout << kernel->values[0] <<endl;
    //fillArray<float>(file, &(biases->values));
    toRead = biases->values.size() * sizeof(float);
    file->read((char *) biases->values.data(), toRead);

    //We get the activation.
    activation = getActivation(file);
    cout << "created conv" << endl;
}


std::vector<int> Conv2D::getOutputShapeFor(std::vector<int> *inputShape) {
    assert(inputShape->size()==3);
    assert((*inputShape)[0]==kernel->shape[2]);
    assert(kernel->shape[3] == biases->shape[0]);
    assert(kernel->shape[0]%2 == 1); //works only with odd size kernels.
    assert(kernel->shape[1]%2 == 1); //works only with odd size kernels.


    int newHeight = (*inputShape)[1] - (kernel->shape[0]-1);
    int newWidth = (*inputShape)[2] - (kernel->shape[1]-1);

    return std::vector<int>({biases->shape[0],newHeight, newWidth});
}


void Conv2D::call(MultiDimArray *in, MultiDimArray *out) {

    for(int i=0; i<out->shape[0];i++){
        for(int j=0; j<out->shape[1];j++){
            for(int k=0; k<out->shape[2];k++){

                /* Now that we know where to put the value we will compute,
                we just have to iterate through the correct part of the kernel*/
                float sum = 0;
                for(int l=0; l<kernel->shape[2];l++){
                    for(int m=0; m<kernel->shape[0]; m++){
                        for(int n=0; n<kernel->shape[1];n++){
                            sum+= (*(in->get(l,j+m,k+n))) * (*(kernel->get(m,n,l,i)));
                        }
                    }
                }
                sum +=biases->values[i];
                *(out->get(i,j,k)) = sum;
            }
        }
    }

    Activation actLayer(activation);
    actLayer.call(out, out);
    cout<< "out first conv: " << *(out->get(15,16,14))<<endl;
}
