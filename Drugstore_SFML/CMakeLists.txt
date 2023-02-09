cmake_minimum_required(VERSION 3.24)
project(app)

set(CMAKE_CXX_STANDARD 20)

add_executable(app main.cpp shuffle.cpp prescription.cpp check.cpp menu.cpp engine.cpp headers/engine.h)
include_directories(headers /usr/include c:/SFML/include)
set(SFML_ROOT c:/SFML)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(app ${SFML_LIBRARIES})
endif()

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})


if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()