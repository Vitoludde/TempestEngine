cmake_minimum_required(VERSION 3.0)

project(TempestEngine)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

# Add OpenGL to build
add_subdirectory(${CMAKE_SOURCE_DIR}/external/OpenGL/)

# Wildcard files from /src/ and add executable (Target)
file(GLOB SOURCES "src/*")
add_executable(TempestEngine ${SOURCES})

# Link OpenGL
target_link_libraries(TempestEngine glfw)

# Wildcard shader and image files
file(GLOB SHADERS "${CMAKE_SOURCE_DIR}/src/shaders/*")
file(GLOB IMAGES "${CMAKE_SOURCE_DIR}/src/images/*")

# Now we need to copy our shaders and our images
add_custom_command(TARGET TempestEngine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/src/shaders
        $<TARGET_FILE_DIR:TempestEngine>/shaders
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/src/images
        $<TARGET_FILE_DIR:TempestEngine>/images
    COMMAND ${CMAKE_COMMAND} -E copy
        ${SHADERS}
        $<TARGET_FILE_DIR:TempestEngine>/shaders
    COMMAND ${CMAKE_COMMAND} -E copy
        ${IMAGES}
        $<TARGET_FILE_DIR:TempestEngine>/images
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