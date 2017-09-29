cmake_minimum_required(VERSION 3.8)
project(cpp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Layer.cpp Layer.h layers/Dense.cpp layers/Dense.h layers/Conv2D.cpp layers/Conv2D.h layers/Flatten.cpp layers/Flatten.h layers/Activation.cpp layers/Activation.h layers/MaxPooling2D.cpp layers/MaxPooling2D.h Model.cpp Model.h MultiDimArray.cpp MultiDimArray.h arrays/Array1D.cpp arrays/Array1D.h arrays/Array2D.cpp arrays/Array2D.h arrays/Array3D.cpp arrays/Array3D.h arrays/Array4D.cpp arrays/Array4D.h)
add_executable(cpp ${SOURCE_FILES})