add_executable(bot bot.cpp)
target_compile_features(bot PRIVATE cxx_std_17)

target_link_libraries(bot PRIVATE codecup_library)
