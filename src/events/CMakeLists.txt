add_library(events STATIC kbEvents.cpp)
target_include_directories(events PUBLIC ${PROJECT_SOURCE_DIR}/inc)

add_library(eventDispatcher STATIC kbEventDispatcher.cpp)
target_include_directories(eventDispatcher PUBLIC ${PROJECT_SOURCE_DIR}/inc)
target_link_libraries(eventDispatcher PUBLIC kbOutput)