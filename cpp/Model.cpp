//
// Created by smith on 9/29/2017.
//
#include <iostream>
#include <c++/memory>
#include <c++/fstream>
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
                layerPtr = new Dense(&file);
            case 2:
                layerPtr = new Conv2D(&file);
            case 3:
                layerPtr = new Flatten();
            case 4:
                layerPtr = new Activation(&file);
            case 5:
                layerPtr = new MaxPooling2D(&file);

            default:break;
        }
        layers.push_back(layerPtr);
    }

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
