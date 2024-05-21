#!/bin/bash

SCRIPT_DIR="$(dirname "$(readlink -f "$0")")"
Help () {
    echo "Usage:"
    echo -e "\t./build.sh"
    echo "Options:"
    echo -e "\t-c\t\tCleans the build area."
    echo -e "\t-f\t\tFormats All the Files with Clang-Format."
    echo -e "\t-h\t\tDisplays this help information."
    echo -e "\t-i\t\tGenerates IDL files for FastDDS."
    echo -e "\t-q\t\tJust recompiles code."
    echo -e "\t-u\t\tPerforms Unit Tests."
}

Clean () {
    if [ -d ${SCRIPT_DIR}/build ]; then
        echo "Cleaning Build directory."
        rm -rf ${SCRIPT_DIR}/build
    fi

    if [ -d ${SCRIPT_DIR}/FastDDSMessages/src ]; then
        echo "Cleaning FastDDS Generated Code."
        rm -rf ${SCRIPT_DIR}/FastDDSMessages/src
    fi

    echo "Directory Cleaned."
}

Format() {
    find . -type d \( -path ./build -o -path ./FastDDSMessages -o -path ./GUI/GDExtension \) -prune \
        -o -iname *.h -o -iname *.c -o -iname *.cpp -o -iname *.hpp \
        | xargs clang-format -style=file -i -fallback-style=none   
}

IDL () {
    if [ -d ${SCRIPT_DIR}/FastDDSMessages/src ]; then
        echo "Cleaning FastDDS Generated Code."
        rm -rf ${SCRIPT_DIR}/FastDDSMessages/src
    fi

    mkdir ${SCRIPT_DIR}/FastDDSMessages/src
    for idl in ${SCRIPT_DIR}/FastDDSMessages/idl/*
    do
        idlName=${idl##*/}
        echo "Generating code for: ${idlName}"
        fastddsgen -d FastDDSMessages/src -flat-output-dir ${idl}
    done    
}

QuickBuild () {
    if [ -d ${SCRIPT_DIR}/build ]
    then
        cmake --build ${SCRIPT_DIR}/build -j 8
    else
        echo "Can't perform quick build. Run full script first "./build.sh""
        exit 1
    fi
}

UnitTest(){
    if [ -d ${SCRIPT_DIR}/build ]
    then
        ctest --test-dir ${SCRIPT_DIR}/build -V --stop-on-failure -O build/UnitTestReport
    else
        echo "Can't perform unit test. Build directory doesnt exist."
        exit 1
    fi
}

NormalBuild () {
    Clean
    echo "Creating Build directory."
    mkdir ${SCRIPT_DIR}/build
    echo "Generating code from IDL's."
    IDL
    echo "Formatting files."
    Format
    echo "Configuring CMake."
    cmake -DCMAKE_BUILD_TYPE=DEBUG -S ${SCRIPT_DIR} -B ${SCRIPT_DIR}/build
    echo "Compiling code."
    QuickBuild
}

while getopts ":hcqifu" arg; do
    case $arg in
        u)
            UnitTest
            exit 1
            ;;
        h)
            Help
            exit 1
            ;;
        f)
            Format
            exit 1
            ;;    
        c)
            Clean
            exit 1
            ;;
        q)
            QuickBuild
            exit 1
            ;;
        i)
            IDL
            exit 1
            ;;   
        ?)
            echo "Invalid option selected"
            exit 1
            ;;
    esac
done

NormalBuild



