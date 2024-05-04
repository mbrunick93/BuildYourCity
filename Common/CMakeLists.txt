project(common)

file(GLOB COMMON_SOURCES_CXX "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_library(common ${COMMON_SOURCES_CXX})
target_include_directories(common PUBLIC    ${CMAKE_CURRENT_SOURCE_DIR}/include
                                            ${CMAKE_CURRENT_SOURCE_DIR}/../FastDDSMessages/src)
target_link_libraries(common PUBLIC FastDDSMessages fastrtps fastcdr)


