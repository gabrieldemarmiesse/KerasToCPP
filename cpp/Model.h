//
// Created by smith on 9/29/2017.
//

#ifndef CPP_MODEL_H
#define CPP_MODEL_H

#include <iostream>
#include <c++/memory>
#include "Layer.h"

class Model {

    public:
    explicit Model(std::string myString);
    std::shared_ptr<MultiDimArray> predict(MultiDimArray *input);

    private:
    std::vector<std::shared_ptr<Layer>> layers;
};


#endif //CPP_MODEL_H
