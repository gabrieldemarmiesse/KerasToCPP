#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>
#include "Model.h"
#include "arrays/Array2D.h"
#include "arrays/Array3D.h"
#include "arrays/Array4D.h"


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

    Array3D input(1, 28,28,false);

    auto buffer = readFile(argv[2]);
    for(int i=0; i<buffer.size(); i++)
        input.values[i] = buffer[i];
    for(int j=0; j<input.shape[1]; j++){
        for(int i=0; i<input.shape[2]; i++){
            if (input.access(0,j,i)>0){
                cout << "1";
            }else{
                cout << "0";
            }
        }
        cout << endl;
    }


    return 0;
}
