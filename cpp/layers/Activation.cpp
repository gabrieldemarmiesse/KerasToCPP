//
// Created by smith on 9/29/2017.
//
#include <cmath>
#include <utility>
#include <c++/cassert>
#include "Activation.h"
using namespace std;


Activation::Activation(std::string str) {
    act = std::move(str);
}


Activation::Activation(std::ifstream *file) {
    cout << "Creating an Activation layer from file is not implemented."<< endl;
    assert(false);
}


std::vector<int> Activation::getOutputShapeFor(std::vector<int> *inputShape) {
    return *inputShape;
}


void Activation::call(const MultiDimArray& in, MultiDimArray& out) {
    if(act == "linear"){
        for(int i=0; i<in.values.size(); i++)
            out.values[i] = in.values[i];
    }else if (act =="relu"){
        for(int i=0; i<in.values.size(); i++){
            float value = in.values[i];
            if(value<0){
                out.values[i] = 0;
            }else{
                out.values[i] = value;
            }
        }

    }else if(act=="softmax"){
        float sum = 0;
        for(int i=0; i<in.values.size(); i++){
            out.values[i] = exp(in.values[i]);
            sum += out.values[i];
        }
        for (float & value : out.values) {
            value /= sum;
        }

    }else{
        cout<<"Unexpected activation: "<< act<<endl;
        assert(false);
    }
}
