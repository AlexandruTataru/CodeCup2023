FetchContent_Declare(
  catch
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v2.13.6)
FetchContent_MakeAvailable(catch)

add_executable(tests tests.cpp)
target_compile_features(tests PRIVATE cxx_std_17)
target_link_libraries(tests PRIVATE Catch2::Catch2)
target_include_directories(tests PUBLIC ../include)

add_test(NAME codecup_tests COMMAND tests)