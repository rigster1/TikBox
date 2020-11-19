# wlpp Copyright 2020 Max Burns
# See LICENSE for more information.
#
# Created by chez4 19/11/20

add_executable(tikbox main.cpp net/socket.cpp)

target_include_directories(tikbox PRIVATE
        "${tikbox_SOURCE_DIR}/src"
        "${tikbox_BINARY_DIR}/src"
        ${tikbox_INCLUDE_DIRS})

set_target_properties(tikbox PROPERTIES
        CXX_STANDARD 20
        CXX_EXTENSIONS OFF)
