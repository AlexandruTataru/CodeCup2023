add_executable(tests tests.cpp)
target_compile_features(tests PRIVATE cxx_std_17)
target_include_directories(tests PUBLIC ../include)

add_test(NAME codecup_tests COMMAND tests)