project(fastddsmessages)

file(GLOB FAST_DDS_MESSAGES_SOURCES_CXX "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cxx")

add_library(fastddsmessages ${FAST_DDS_MESSAGES_SOURCES_CXX})
target_include_directories(fastddsmessages PUBLIC src)