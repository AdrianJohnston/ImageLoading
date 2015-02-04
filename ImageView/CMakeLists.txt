cmake_minimum_required (VERSION 2.6)

project (ImageViewing)

#Set the Executable Name
set(EXEC_NAME image_view)

#Set the source files
set(SRC_FILES main.cpp stb_image.h)

add_executable(${EXEC_NAME} ${SRC_FILES})

#Set the libraries to link to
target_link_libraries(${EXEC_NAME}
	${ALL_LIBS}
)


##This is incredibly useful code. It will copy the executables to the source directories. Thereby removing any need to set the working
## directory.
add_custom_command(
   TARGET ${EXEC_NAME} POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/${EXEC_NAME}${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/"
)