add_executable(bot bot.cpp)
target_compile_features(bot PRIVATE cxx_std_17)
target_include_directories(bot PUBLIC ../include)
