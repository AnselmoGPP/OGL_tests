
CMAKE_MINIMUM_REQUIRED(VERSION 3.1...3.15)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
	CMAKE_POLICY(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
ENDIF()

MESSAGE(STATUS "CMake version: " ${CMAKE_MAJOR_VERSION} "." ${CMAKE_MINOR_VERSION})

#ADD_SUBDIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/extern/glfw/glfw-3.3)

PROJECT(project_name
	VERSION 1.0
	DESCRIPTION "This is for CMake testing"
	LANGUAGES CXX)

FIND_PACKAGE(OpenCV REQUIRED PATHS ${CMAKE_CURRENT_SOURCE_DIR}/../opencv-4.1.1/_BUILD)

set(target_name ${PROJECT_NAME})


ADD_EXECUTABLE(${target_name}	 # Name of the executable and the target
	src/main.cpp
	src/header.cpp
	# headers are ignored. We list them to show them up in the IDE
	headers/header.hpp
)

SET_PROPERTY(
	TARGET ${PROJECT_NAME} 
	PROPERTY CXX_STANDARD 14
)

add_definitions(
	-std=c++11
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)
ADD_COMPILE_DEFINITIONS(
	GLEW_STATIC=1
	IMGUI_IMPL_OPENGL_LOADER_GLEW=1
)
target_compile_definitions(${PROJECT_NAME} PRIVATE NEW_MACRO=${my_dir})

#ADD_LIBRARY(${target_name}  STATIC  # STATIC SHARED MODULE 
#	src/main.cpp
#	src/header.cpp
#	headers/header.hpp)

TARGET_INCLUDE_DIRECTORIES(${target_name} PUBLIC	# PUBLIC PRIVATE INTERFACE
	headers
)

TARGET_LINK_LIBRARIES(${target_name} PUBLIC
	#target_B
	#abc.lib
)
