cmake_minimum_required(VERSION 3.8)
project(cpp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Layer.cpp Layer.h layers/Dense.cpp layers/Dense.h layers/Conv2D.cpp layers/Conv2D.h layers/Flatten.cpp layers/Flatten.h layers/Activation.cpp layers/Activation.h layers/MaxPooling2D.cpp layers/MaxPooling2D.h Model.cpp Model.h MultiDimArray.cpp MultiDimArray.h utils.cpp)
add_executable(cpp ${SOURCE_FILES})