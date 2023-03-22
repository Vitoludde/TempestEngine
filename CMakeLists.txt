cmake_minimum_required(VERSION 3.0)

project(CMakeTutorial)

# Set lib paths
SET(OPENGL_LIB ${CMAKE_SOURCE_DIR}/external/OpenGL/libs)

# Set include paths
SET(GLAD_INCLUDE ${CMAKE_SOURCE_DIR}/external/OpenGL/include/glad)
SET(KHR_INCLUDE ${CMAKE_SOURCE_DIR}/external/OpenGL/include/KHR)
SET(GLFW_INCLUDE ${CMAKE_SOURCE_DIR}/external/OpenGL/include/GLFW)
SET(OPENGL_INCLUDE ${CMAKE_SOURCE_DIR}/external/OpenGL/include)

# Include our paths
include_directories(${OPENGL_INCLUDE})
include_directories(${GLFW_INCLUDE})
include_directories(${KHR_INCLUDE})
include_directories(${GLAD_INCLUDE})





# Wildcard files and add executable (Target)
file(GLOB SOURCES "src/*")
add_executable(CMakeTutorial ${SOURCES})

# Link OpenGL
target_link_libraries(CMakeTutorial ${OPENGL_LIB}/glfw3.lib)






# Wildcard shader and image files
file(GLOB SHADERS "${CMAKE_SOURCE_DIR}/src/shaders/*")
file(GLOB IMAGES "${CMAKE_SOURCE_DIR}/src/images/*")

# Now we need to copy our shaders and our images
add_custom_command(TARGET CMakeTutorial POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/src/shaders
        $<TARGET_FILE_DIR:CMakeTutorial>/shaders
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/src/images
        $<TARGET_FILE_DIR:CMakeTutorial>/images
    COMMAND ${CMAKE_COMMAND} -E copy
        ${SHADERS}
        $<TARGET_FILE_DIR:CMakeTutorial>/shaders
    COMMAND ${CMAKE_COMMAND} -E copy
        ${IMAGES}
        $<TARGET_FILE_DIR:CMakeTutorial>/images
)


add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/src/shaders
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/shaders
    COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/src/shaders/vertexshader.shader
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/shaders/
    COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/src/shaders/fragmentshader.shader
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/shaders/

    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/src/images
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/images
    COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/src/images/container.jpg
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/images/
)