#!/bin/bash

BUILD_FOLDER="build"

help()
{
    echo "Welcome to ECSess's installation guide for unix systems."
}

build_release()
{
    mkdir $BUILD_FOLDER
    cd $BUILD_FOLDER
    cmake -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ ../
    make
    cd ..    
}

build_debug()
{
    mkdir $(BUILD_FOLDER)
    cd $(BUILD_FOLDER)
    cmake -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_CXX_FLAGS=-DDEBUG_MODE ../
    make
    cd ..
}

clean()
{
    rm -rf $BUILD_FOLDER
    echo -e "\033[32mCompletly cleaned $BUILD_FOLDER folder.\033[0m"
}

if [ "$1" == "release" ]
then
    clean
    build_release
elif [ "$1" == "debug" -o "$1" == "re" ]
then
    clean
    build_debug
elif [ "$1" == "help" ]
then
    help
elif [ "$1" == "clean" ]
then
    clean
else
    build_debug
fi
