//
// Created by smith on 9/29/2017.
//
#include <iostream>
#include <c++/memory>
#include <c++/fstream>
#include <c++/cassert>
#include "Model.h"
#include "layers/Activation.h"
#include "layers/Dense.h"
#include "layers/Conv2D.h"
#include "layers/Flatten.h"
#include "layers/MaxPooling2D.h"

using namespace std;

Model::Model(string myString) {

    ifstream file(myString,ios::binary);

    unsigned int numberLayers;
    file.read((char *)&numberLayers, sizeof(unsigned int));

    for(int i=0; i<numberLayers; i++){
        unsigned int idLayer;
        file.read((char*) &idLayer,sizeof(unsigned int));

        shared_ptr<Layer> layerPtr;
        switch (idLayer){
            case 1:
                layerPtr.reset(new Dense(&file));
                break;
            case 2:
                layerPtr.reset(new Conv2D(&file));
                break;
            case 3:
                layerPtr.reset(new Flatten());
                break;
            case 4:
                layerPtr.reset(new Activation(&file));
                break;
            case 5:
                layerPtr.reset(new MaxPooling2D(&file));
                break;
            default:
                assert(false);
        }
        layers.push_back(layerPtr);
    }

}

shared_ptr<MultiDimArray> Model::predict(MultiDimArray* input) {

    shared_ptr<MultiDimArray> pointerIn;

    for (int i=0; i<layers.size(); i++) {
        MultiDimArray* raw_ptr= nullptr;
        if(i==0){
            raw_ptr = input;
        }else{
            raw_ptr = pointerIn.get();
        }
        shared_ptr<MultiDimArray> pointerOut(new MultiDimArray(layers[i]->getOutputShapeFor(&(raw_ptr->shape))));
        layers[i]->call(*raw_ptr, *pointerOut);

        pointerIn = pointerOut;
    }
    return pointerIn;
}
