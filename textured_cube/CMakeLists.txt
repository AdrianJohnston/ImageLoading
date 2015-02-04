#CMake entry point
cmake_minimum_required (VERSION 2.6)

project (textured_cube)

#Set the Executable Name
set(EXEC_NAME textured_cube)

add_executable(${EXEC_NAME}
	tutorial05.cpp
	../common/shader.cpp
	../common/shader.hpp
	../common/texture.cpp
	../common/texture.hpp
	TransformVertexShader.vertexshader
	TextureFragmentShader.fragmentshader
)

target_link_libraries(${EXEC_NAME}
	${ALL_LIBS}
)

#Special command to allow integration with XCODE - This may not work
#set_target_properties(textured_cube PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/textured_cube/")

##This is incredibly useful code. It will copy the executables to the source directories. Thereby removing any need to set the working
## directory.
add_custom_command(
   TARGET ${EXEC_NAME} POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/${EXEC_NAME}${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/"
)