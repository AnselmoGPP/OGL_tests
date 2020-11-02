CMAKE_MINIMUM_REQUIRED(VERSION 3.12)
PROJECT(6_Shader_class)

FIND_PACKAGE(OpenGL REQUIRED)

ADD_DEFINITIONS(
	-std=c++11
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)
ADD_COMPILE_DEFINITIONS( GLEW_STATIC=1 )
ADD_COMPILE_DEFINITIONS( IMGUI_IMPL_OPENGL_LOADER_GLEW=1 )

ADD_EXECUTABLE(${PROJECT_NAME}
	src/main.cpp
	src/auxiliar.cpp
	src/shader.cpp

	shaders/vertexShader.vs
	shaders/fragmentShader.fs
)

TARGET_SOURCES(${PROJECT_NAME} PRIVATE
	src/auxiliar.hpp
	src/shader.hpp
)

TARGET_SOURCES(${PROJECT_NAME} PRIVATE
	../../extern/glad/src/glad.c
	../../extern/glew/glew-2.1.0/src/glew.c

	../../extern/imgui/imgui-1.72b/imgui.cpp
	../../extern/imgui/imgui-1.72b/imgui_demo.cpp
	../../extern/imgui/imgui-1.72b/imgui_draw.cpp
	../../extern/imgui/imgui-1.72b/imgui_widgets.cpp
	../../extern/imgui/imgui-1.72b/examples/imgui_impl_glfw.cpp
	../../extern/imgui/imgui-1.72b/examples/imgui_impl_opengl3.cpp
)

TARGET_INCLUDE_DIRECTORIES( ${PROJECT_NAME} PUBLIC
	../../extern/glew/glew-2.1.0/include
	../../extern/glad/include
	../../extern/glfw/glfw-3.3.2/include
	../../extern/glm/glm-0.9.9.5
	../../extern/imgui/imgui-1.72b
)

if( WIN32 )
	TARGET_LINK_LIBRARIES( ${PROJECT_NAME} 
		optimized	${OPENGL_LIBRARY} 
		optimized	${PROJECT_SOURCE_DIR}/../../_BUILD/extern/glfw/glfw-3.3.2/src/Release/glfw3.lib
		#optimized	${PROJECT_SOURCE_DIR}/../../_BUILD/lib/Release/libglew32.lib
		#optimized	${PROJECT_SOURCE_DIR}/../../_BUILD/extern/glm/glm-0.9.9.5/glm/Release/glm_static.lib
	)
endif()

if( UNIX )
	TARGET_LINK_LIBRARIES( ${PROJECT_NAME} 
		optimized	${OPENGL_LIBRARY} 
		optimized	${PROJECT_SOURCE_DIR}/../../_BUILD/extern/glfw/glfw-3.3.2/src/libglfw3.a
		#optimized	${PROJECT_SOURCE_DIR}/../../_BUILD/lib/libGLEW.a
		#optimized	${PROJECT_SOURCE_DIR}/../../_BUILD/extern/glm/glm-0.9.9.5/glm/libglm_static.a
		-lGL -lGLU -lXrandr -lXext -lX11 -lrt -ldl -lpthread -lm
	)
endif()




#INSTALL(TARGETS ${PROJECT_NAME} DESTINATION ${CURRENT_CMAKE_DIR}/bin)
