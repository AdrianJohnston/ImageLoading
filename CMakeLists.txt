# CMake entry point
cmake_minimum_required (VERSION 2.6)
project (OpenGL-Examples)

#Find the OpenGL pacakge
find_package(OpenGL REQUIRED)

# Compile external dependencies
add_subdirectory (external)

#Add all of the external library include directories
include_directories(
	external/glfw-3.0.3/include/GLFW/
	external/glm-0.9.4.0/
	external/glew-1.9.0/include/
	.
)

#Set the libraries into a variable for linking (performed in each project)
set(ALL_LIBS
	${OPENGL_LIBRARY}
	GLFW_303
	GLEW_190
)

#Some other required definitions.
add_definitions(
	-DGLEW_STATIC #I believe this is the only required one
	-D_CRT_SECURE_NO_WARNINGS #Stops warnings on Visual Studio
)

#Add general code. Useful when using an IDE
SOURCE_GROUP(common REGULAR_EXPRESSION ".*/common/.*" )
SOURCE_GROUP(shaders REGULAR_EXPRESSION ".*/.*shader$" )

# Build the independant projects. Global state is passed to each one e.g. External Dependencies
add_subdirectory(textured_cube)
add_subdirectory(TinyObjTest)
add_subdirectory(Images)
add_subdirectory(ImageView)









