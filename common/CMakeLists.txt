file(GLOB COMMON_SRC *.cpp)
file(GLOB COMMON_HDRS include/*.h)
add_library(common ${COMMON_SRC} ${COMMON_HDRS})
target_include_directories(common PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

pybind11_add_module(euler_common_py bindings/bindings.cpp)
target_link_libraries(euler_common_py PUBLIC common)

add_subdirectory(test)
