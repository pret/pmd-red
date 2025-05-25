cmake_minimum_required (VERSION 3.15)
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")
set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "")
set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "")
# Override the default system to cross-compile for ARM processors
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR ARM)
project(pmd-red)

enable_language(ASM)

if(APPLE)
    include_directories(/usr/local/include)
endif(APPLE)

file(GLOB_RECURSE c_srcs src/*.c)
file(GLOB_RECURSE asm_srcs asm/*.s)
add_executable(pmd-red ${c_srcs} ${asm_srcs})
target_include_directories(pmd-red PUBLIC tools/agbcc/include)
target_include_directories(pmd-red PRIVATE include)
target_compile_definitions(pmd-red PRIVATE __APPLE__)
