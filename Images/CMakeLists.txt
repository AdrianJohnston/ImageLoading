cmake_minimum_required (VERSION 2.6)

project (ImageLoading)

#Set the Executable Name
set(EXEC_NAME stb_image_test)

#Set the source files
set(SRC_FILES main.cpp stb_image.h)

add_executable(${EXEC_NAME} ${SRC_FILES})

add_custom_command(
   TARGET ${EXEC_NAME} POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/${EXEC_NAME}${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/"
)