#CMake entry point
cmake_minimum_required (VERSION 2.6)
project (TinyObjTest)

set(SRC_FILES main.cpp ../common/tiny_obj_loader.cc)

add_executable(main ${SRC_FILES})