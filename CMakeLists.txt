cmake_minimum_required(VERSION 3.10)
project(euler)

find_package(Catch2 REQUIRED)

set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_INCLUDE_WHAT_YOU_USE "/usr/bin/iwyu;-Xiwyu;any;-Xiwyu;iwyu;-Xiwyu;args")
set(CMAKE_CXX_CLANG_TIDY "/usr/bin/clang-tidy")

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Conan package manager
if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
  include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
  conan_basic_setup(TARGETS)
else()
  message(WARNING "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif()

add_subdirectory(common)

file(GLOB PROBLEM_SUBDIRS [0-9]*.cpp)
add_library(runner runner.cpp)
foreach(PROBLEM ${PROBLEM_SUBDIRS})
  get_filename_component(PROBLEM_TARGET ${PROBLEM} NAME_WE)
  add_executable(${PROBLEM_TARGET} ${PROBLEM})
  target_include_directories(${PROBLEM_TARGET} PRIVATE)
  target_link_libraries(${PROBLEM_TARGET} runner common fmt stdc++fs CONAN_PKG::gmp)
endforeach()
