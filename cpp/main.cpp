#include <iostream>
#include <vector>
#include <c++/fstream>
#include <c++/cassert>
#include <c++/limits>
#include <chrono>
#include "layers/Activation.h"
#include "Model.h"


using myType = uint8_t;
using namespace std;
using Clock = std::chrono::steady_clock;
using std::chrono::time_point;

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

    assert(argc == 3);

    for(int i=0; i<argc; i++)
        cout << argv[i] << endl;

    //We get the input.
    MultiDimArray input({1,28,28});
    auto buffer = readFile(argv[2]);
    for(int i=0; i<buffer.size(); i++){
        input.values[i] = buffer[i];
        input.values[i] /= 255;
    }

    //Prediction
    Model model(argv[1]);
    auto start = chrono::steady_clock::now();
    auto ptrOutput = model.predict(&input);
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout <<"Executed in "<< chrono::duration <double, nano> (diff).count() << " ns" << endl;

    for(int i=0; i<ptrOutput->shape[0];i++){
        cout <<"Confidence of this number being ";
        cout <<i<<": " << *(ptrOutput->get(i))*100<<"%"<<endl;
    }

    cout << "Program exited properly.";
    return 0;



}
