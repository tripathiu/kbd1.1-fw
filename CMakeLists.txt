cmake_minimum_required(VERSION 3.0.0)
project(kbd-fw VERSION 0.1.0)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_subdirectory(${PROJECT_SOURCE_DIR}/src/debug)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/events)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/keys)
add_subdirectory(${PROJECT_SOURCE_DIR}/src/keymatrix)

add_executable(kbd-fw main.cpp)
target_include_directories(kbd-fw PUBLIC ${PROJECT_SOURCE_DIR}/inc)
target_link_libraries(kbd-fw PUBLIC
    kbDebug 
    eventDispatcher
    kbKeyMatrix
    events)
