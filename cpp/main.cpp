#include <iostream>
#include <vector>
#include <fstream>
#include "layers/Activation.h"
#include "Model.h"


using myType = uint8_t;
using namespace std;

vector<myType> readFile(char *path){
    ifstream is;
    std::vector<myType> rawfilebuffer;

    is.open(path, std::ios::binary);
    is.seekg(0, std::ios::end);
    size_t filesize= static_cast<size_t>(is.tellg());
    is.seekg(0, std::ios::beg);

    rawfilebuffer.resize(filesize/sizeof(myType));

    is.read((char *)rawfilebuffer.data(), filesize);
    return rawfilebuffer;
}


int main(int argc, char *argv[]) {

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
        input.values[i] -= 0.5;
    }

    Model model("yolo");
    auto pointer = model.predict(&input);



    cout << "yolo";
    /*for(int j=0; j<input2.shape[1]; j++){
        for(int i=0; i<input2.shape[2]; i++){
            if (input2.access(0,j,i)>1000000){
                cout << "1";
            }else{
                cout << input2.access(0,j,i);
            }
        }
        cout << endl;
    }*/


    return 0;
}
