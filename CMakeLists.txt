cmake_minimum_required(VERSION 3.20)

project(BuildYourCity)

if(NOT fastcdr_FOUND)
    find_package(fastcdr 2 REQUIRED)
endif()

if(NOT fastrtps_FOUND)
    find_package(fastrtps 2.12 REQUIRED)
endif()

add_subdirectory(FastDDSMessages)