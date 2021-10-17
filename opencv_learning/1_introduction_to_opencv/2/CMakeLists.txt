cmake_minimum_required(VERSION 3.16)
project( 1_2_get_start_with_image )

find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( ${PROJECT_NAME} main.cpp )

target_link_libraries( ${PROJECT_NAME} ${OpenCV_LIBS} )
