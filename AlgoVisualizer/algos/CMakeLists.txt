file(GLOB_RECURSE SRC_FILES src/*.cpp)
file(GLOB_RECURSE INC_FILES include/*.h)

add_library(${PROJECT_NAME}_ALGOS ${SRC_FILES})

target_include_directories(${PROJECT_NAME}_ALGOS PUBLIC include)