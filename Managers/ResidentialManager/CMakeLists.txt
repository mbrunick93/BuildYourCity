project(residentialmanagermain)

file(GLOB RESIDENTIAL_MANAGER_SOURCES_CXX "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_library(residentialmanager ${RESIDENTIAL_MANAGER_SOURCES_CXX})
target_include_directories(residentialmanager PUBLIC    ${CMAKE_CURRENT_SOURCE_DIR}/include
                                                        ${CMAKE_SOURCE_DIR}/Common/include
                                                        ${CMAKE_SOURCE_DIR}/Modules/Residential/include)

add_executable(residentialmanagermain ResidentialManagerMain.cpp)
target_link_libraries(residentialmanagermain PUBLIC common 
                                                    fastddsmessages 
                                                    residentialmanager 
                                                    residentialmodules)
