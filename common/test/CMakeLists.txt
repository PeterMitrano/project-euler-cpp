add_library(test_main main.cpp)

file(GLOB TEST_SRC *_test.cpp)
add_executable(tests ${TEST_SRC})
target_link_libraries(tests test_main common Catch2::Catch2)

include(CTest)
include(Catch)
catch_discover_tests(tests)
