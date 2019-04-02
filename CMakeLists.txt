cmake_minimum_required(VERSION 3.0.0)
project(asd VERSION 0.0.1)

SET(CMAKE_BUILE_TYPE DEBUG) #debug模式
set(CMAKE_CXX_STANDARD 11) #c++11


add_executable(asd sort/sort.cpp graph/utils.h)

# 通用包含目录
# include_directories("${PROJECT_SOURCE_DIR}")


# opencv 通用配置
# set(OpenCV_DIR "F:\\opencv_cross")
# FIND_PACKAGE(OpenCV REQUIRED)
# include_directories(${OpenCV_INCLUDE_DIRS})
# target_link_libraries(asd ${OpenCV_LIBS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
