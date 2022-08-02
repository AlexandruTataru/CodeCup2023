cmake_minimum_required(VERSION 3.11...3.23)

project(
  LSEG_RO_atataru
  VERSION 0.1
  DESCRIPTION "Bot for CodeCup 2023 competition"
  LANGUAGES CXX)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  set(CMAKE_CXX_EXTENSIONS OFF)
  include(CTest)
endif()

add_subdirectory(src)

add_subdirectory(tests)