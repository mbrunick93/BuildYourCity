project(simulationmanagermain)

file(GLOB SIMULATION_MANAGER_SOURCES_CXX "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_library(simulationmanager ${SIMULATION_MANAGER_SOURCES_CXX})
target_include_directories(simulationmanager PUBLIC    ${CMAKE_CURRENT_SOURCE_DIR}/include
                                                        ${CMAKE_SOURCE_DIR}/Common/include
                                                        ${CMAKE_SOURCE_DIR}/FastDDSMessages/src

                                                        )

add_executable(simulationmanagermain SimulationManagerMain.cpp)
target_link_libraries(simulationmanagermain PUBLIC common 
                                                    fastddsmessages 
                                                    simulationmanager
                                                    )
