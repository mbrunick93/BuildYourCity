project(Common)

file(GLOB COMMON_SOURCES_CXX "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_library(Common ${COMMON_SOURCES_CXX})
target_include_directories(Common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
${CMAKE_CURRENT_SOURCE_DIR}/../FastDDSMessages/src)

add_executable(TestMain CommonTest.cpp)
target_link_libraries(TestMain Common FastDDSMessages fastrtps fastcdr)

add_executable(TestMainSub CommonTestSub.cpp)
target_link_libraries(TestMainSub Common FastDDSMessages fastrtps fastcdr)
