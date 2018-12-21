file(GLOB COMMON_SRC *.cpp)
file(GLOB COMMON_HDRS include/*.h)
add_library(common ${COMMON_SRC} ${COMMON_HDRS})
target_include_directories(common PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

add_subdirectory(test)
