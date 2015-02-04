#CMake entry point
cmake_minimum_required (VERSION 2.6)

project (TinyObjTest)

#Set the Executable Name
set(EXEC_NAME tinyobjtest)

#Set the source files
set(SRC_FILES main.cpp ../common/tiny_obj_loader.cc)

add_executable(${EXEC_NAME} ${SRC_FILES})


##This is incredibly useful code. It will copy the executables to the source directories. Thereby removing any need to set the working
## directory.
add_custom_command(
   TARGET ${EXEC_NAME} POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/${EXEC_NAME}${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/"
)