cmake_minimum_required(VERSION 3.0)

project(TempestEngine)

# GLFW build variables
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

# Add OpenGL and FMTLIB to build
add_subdirectory(${CMAKE_SOURCE_DIR}/external/OpenGL/)
add_subdirectory(${CMAKE_SOURCE_DIR}/external/fmt/)
add_subdirectory(${CMAKE_SOURCE_DIR}/external/glm/)

# Wildcard files from /src/ and add executable (Target)
file(GLOB SOURCES "src/*")
add_executable(TempestEngine ${SOURCES})

# Set C++ standard
set_property(TARGET TempestEngine PROPERTY CXX_STANDARD 20)

# Link OpenGL, FMTLIB
target_link_libraries(TempestEngine glfw)
target_link_libraries(TempestEngine fmt::fmt)
target_link_libraries(TempestEngine glm)

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