cmake_minimum_required(VERSION 3.10)

project(terminal-graph-solver)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "src/*.h")  # opzionale, utile per IDE

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/instances $<TARGET_FILE_DIR:${PROJECT_NAME}>/instances
)

target_include_directories(${PROJECT_NAME} PRIVATE src)