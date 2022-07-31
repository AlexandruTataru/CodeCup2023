add_executable(tests tests.cpp)

# I'm using C++17 in the test
target_compile_features(tests PRIVATE cxx_std_17)

# Should be linked to the main library, as well as the Catch2 testing library
target_link_libraries(tests PRIVATE codecup_library)

add_test(NAME codecup_tests COMMAND tests) # Command can be a target