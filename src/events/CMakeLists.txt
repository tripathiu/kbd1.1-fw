add_library(events STATIC kbEvents.cpp)
target_include_directories(events PUBLIC ${PROJECT_SOURCE_DIR}/inc)
