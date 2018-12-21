add_library(test_main test_main.cpp)

add_executable(tests seive_test.cpp)
target_link_libraries(tests test_main common Catch2::Catch2)

include(CTest)
include(Catch)
catch_discover_tests(tests)
