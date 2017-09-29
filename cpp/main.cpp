#include <iostream>
#include "Model.h"
#include "arrays/Array2D.h"
#include "arrays/Array4D.h"


using namespace std;


int main(int argc, char *argv[]) {

    if(argc != 3){
        cout << "You didn't specify the right number of arguments" << endl;
        return -1;
    }
    cout << argc << endl;
    for(int i=0; i<argc; i++)
        cout << argv[i] << endl;
    


    return 0;
}
