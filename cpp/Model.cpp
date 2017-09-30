//
// Created by smith on 9/29/2017.
//
#include <iostream>
#include <c++/memory>
#include "Model.h"
#include "layers/Activation.h"

using namespace std;

Model::Model(string myString) {

    shared_ptr<Activation> act0(new Activation("linear"));
    shared_ptr<Activation> act1(new Activation("softmax"));

    layers.push_back(act0);
    layers.push_back(act1);
}

shared_ptr<MultiDimArray> Model::predict(MultiDimArray *input) {

    shared_ptr<MultiDimArray> pointerIn;

    for (int i=0; i<layers.size(); i++) {
        MultiDimArray* raw_ptr= nullptr;
        if(i==0){
            raw_ptr = input;
        }else{
            raw_ptr = pointerIn.get();
        }
        shared_ptr<MultiDimArray> pointerOut(new MultiDimArray(layers[i]->getOutputShapeFor(&(raw_ptr->shape))));
        layers[i]->call(raw_ptr, pointerOut.get());
        pointerIn = pointerOut;
    }
    return pointerIn;
}
