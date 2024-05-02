#!/bin/bash

SCRIPT_DIR="$(dirname "$(readlink -f "$0")")"
Help () {
    echo "Usage:"
    echo -e "\t./build.sh"
    echo "Options:"
    echo -e "\t-c\t\tCleans the build area."
    echo -e "\t-h\t\tDisplays this help information."
    echo -e "\t-i\t\tGenerates IDL files for FastDDS."
    echo -e "\t-q\t\tJust recompiles code."
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
    cmake --build ${SCRIPT_DIR}/build
}



NormalBuild () {
    Clean
    echo "Creating Build directory."
    mkdir ${SCRIPT_DIR}/build
    echo "Generating code from IDL's"
    IDL
    echo "Configuring CMake."
    cmake -S ${SCRIPT_DIR} -B ${SCRIPT_DIR}/build
    echo "Compiling code."
    QuickBuild
}



while getopts ":hcqi" arg; do
    case $arg in
        h)
            Help
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



