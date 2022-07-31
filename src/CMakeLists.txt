set(HEADER_LIST "${LSEG_RO_atataru_SOURCE_DIR}/include/player.hpp")
set(HEADER_LIST "${LSEG_RO_atataru_SOURCE_DIR}/include/order.hpp")
set(HEADER_LIST "${LSEG_RO_atataru_SOURCE_DIR}/include/chaos.hpp")
set(HEADER_LIST "${LSEG_RO_atataru_SOURCE_DIR}/include/utils.hpp")

# Make an automatic library - will be static or dynamic based on user setting
add_library(codecup_library lib.cpp ${HEADER_LIST})

# We need this directory, and users of our library will need it too
target_include_directories(codecup_library PUBLIC ../include)

# All users of this library will need at least C++11
target_compile_features(codecup_library PUBLIC cxx_std_11)
