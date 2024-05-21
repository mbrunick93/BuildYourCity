project(guicode)

file(GLOB SRC_FILES CONFIGURE_DEPENDS src/*.cpp)

add_library(${PROJECT_NAME} SHARED ${SRC_FILES})
target_link_libraries(${PROJECT_NAME} PUBLIC godot-cpp )
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(FullName ${PROJECT_NAME}.${CMAKE_SYSTEM_NAME}.${CMAKE_BUILD_TYPE}.${CMAKE_SYSTEM_PROCESSOR})
string(TOLOWER ${FullName} LowerName)
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "${LowerName}")

set_target_properties( ${PROJECT_NAME} 
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/GUI/BuildYourCityGodot/bin"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/GUI/BuildYourCityGodot/bin"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/GUI/BuildYourCityGodot/bin"
)