#include <iostream>
#include <vector>
#include <c++/fstream>
#include <c++/cassert>
#include <c++/limits>
#include "layers/Activation.h"
#include "Model.h"


using myType = uint8_t;
using namespace std;

vector<myType> readFile(char *path){
    ifstream is;
    std::vector<myType> rawfilebuffer;

    is.open(path, std::ios::binary);
    is.seekg(0, std::ios::end);
    size_t filesize= is.tellg();
    is.seekg(0, std::ios::beg);

    rawfilebuffer.resize(filesize/sizeof(myType));

    is.read((char *)rawfilebuffer.data(), filesize);
    return rawfilebuffer;
}


int main(int argc, char *argv[]) {

    assert(CHAR_BIT * sizeof (float) == 32);
    assert(numeric_limits<float>::is_iec559);
    //throw invalid_argument("MyFunc argument too large.");
    if(argc != 3){
        cout << "You didn't specify the right number of arguments" << endl;
        return -1;
    }
    cout << argc << endl;
    for(int i=0; i<argc; i++)
        cout << argv[i] << endl;

    MultiDimArray input({1,28,28});

    auto buffer = readFile(argv[2]);
    for(int i=0; i<buffer.size(); i++){
        input.values[i] = buffer[i];
        input.values[i] /= 255;
    }

    Model model(argv[1]);
    auto pointer = model.predict(&input);
    for(auto value: pointer->values)
        cout <<value<<endl;
    cout << "yolo";

    return 0;
}
