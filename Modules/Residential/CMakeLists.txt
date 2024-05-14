project(residentialmodules)

file(GLOB RESIDENTIAL_MODULES_SOURCES_CXX "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_library(residentialmodules ${RESIDENTIAL_MODULES_SOURCES_CXX})
target_include_directories(residentialmodules PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR}/include
                                                    ${CMAKE_SOURCE_DIR}/Common/include)
target_link_libraries(residentialmodules PUBLIC common)


