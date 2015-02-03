#CMake entry point
cmake_minimum_required (VERSION 2.6)

project (TinyObjTest)

#Set the Executable Name
set(EXEC_NAME tinyobjtest)

set(SRC_FILES main.cpp ../common/tiny_obj_loader.cc)

add_executable(tinyobjtest ${SRC_FILES})


add_custom_command(
   TARGET ${EXEC_NAME} POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/${EXEC_NAME}${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/"
)