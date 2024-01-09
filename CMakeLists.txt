cmake_minimum_required(VERSION 3.10)
project("HashTable")

set(CMAKE_EXPORT_COMPILE_COMMANDS on)

# HashTable
file(GLOB_RECURSE SRC_FILES "src/*.cpp")
file(GLOB_RECURSE HPP_FILES "src/*.hpp")
file(GLOB_RECURSE HDR_FILES "src/*.h")

add_executable(HashTable ${SRC_FILES} ${HPP_FILES} ${HDR_FILES})

add_subdirectory(lib/Single_linked_list)
target_include_directories(HashTable PRIVATE lib/Single_linked_list/src)
target_link_libraries(HashTable Single_linked_list)
