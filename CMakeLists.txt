cmake_minimum_required(VERSION 3.10)
project(euler)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_INCLUDE_WHAT_YOU_USE "/usr/bin/iwyu;-Xiwyu;any;-Xiwyu;iwyu;-Xiwyu;args")
set(CMAKE_CXX_CLANG_TIDY "/usr/bin/clang-tidy")

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

find_package(Catch2 REQUIRED)

add_subdirectory(common)

file(GLOB PROBLEM_SUBDIRS [0-9]*.cpp)
foreach(PROBLEM ${PROBLEM_SUBDIRS})
  get_filename_component(PROBLEM_TARGET ${PROBLEM} NAME_WE)
  add_executable(${PROBLEM_TARGET} ${PROBLEM})
  target_link_libraries(${PROBLEM_TARGET} common)
endforeach()
