cmake_minimum_required(VERSION 3.11...3.23)

project(
  LSEG_RO_atataru
  VERSION 0.1
  DESCRIPTION "Bot for CodeCup 2023 competition"
  LANGUAGES CXX)

set(CMAKE_CXX_EXTENSIONS OFF)
include(FetchContent)
include(CTest)

add_subdirectory(src)

add_subdirectory(tests)