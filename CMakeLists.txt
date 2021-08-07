# State Key Lab of CAD&CG Zhejiang Unv.
#
# Author: Jin Huang (hj@cad.zju.edu.cn)
#
# Copyright (c) 2004-2021 <Jin Huang>
# All rights reserved.
#
# Licensed under the MIT License.

cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(
  matrix
  VERSION 0.1.0
  LANGUAGES CXX
)

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(
    FATAL_ERROR
      "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there."
  )
endif()

include(cmake/CPM.cmake)

CPMAddPackage("gh:TheLartians/PackageProject.cmake@1.6.0")

file(GLOB headers "${CMAKE_CURRENT_SOURCE_DIR}include/*.h")

add_library(matrix INTERFACE)
target_include_directories(
    matrix INTERFACE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
                     $<INSTALL_INTERFACE:include/${PROJECT_NAME}-${PROJECT_VERSION}>)

install(FILES ${headers}
    DESTINATION include/zjucad/matrix)

packageProject(
    NAME ${PROJECT_NAME}
    VERSION ${PROJECT_VERSION}
    NAMESPACE zjucad
    BINARY_DIR ${PROJECT_BINARY_DIR}
    INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include
    INCLUDE_DESTINATION include/${PROJECT_NAME}-${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)