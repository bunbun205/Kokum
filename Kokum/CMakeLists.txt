cmake_minimum_required(VERSION 3.16)
project(KokumLib)

# Try to detect AVX support first
include(CheckCXXSourceRuns)

# Test AVX
check_cxx_source_runs("
  #include <immintrin.h>
  int main() {
    __m256 v = _mm256_set1_ps(1.0f);
    (void)v;
    return 0;
  }" HAS_AVX)

# If AVX failed, test SSE
if(NOT HAS_AVX)
    check_cxx_source_runs("
    #include <xmmintrin.h>
    int main() {
      __m128 v = _mm_set1_ps(1.0f);
      (void)v;
      return 0;
    }" HAS_SSE)
else()
    set(HAS_SSE OFF)
endif()

# Configure flags and source folder
if(HAS_AVX)
    message(STATUS "AVX supported - enabling -mavx")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mavx")
    set(ASM_DIR "${CMAKE_CURRENT_SOURCE_DIR}/ASM/avx")
elseif(HAS_SSE)
    message(STATUS "SSE supported - enabling -msse")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -msse")
    set(ASM_DIR "${CMAKE_CURRENT_SOURCE_DIR}/ASM/sse")
else()
    message(FATAL_ERROR "Neither AVX nor SSE are supported on this CPU")
endif()

# Collect ASM files
file(GLOB_RECURSE ASM_SOURCES
        "${ASM_DIR}/*.asm"
)

file(GLOB CPP_SOURCES
        src/*.cpp
)

# Assemble each .asm file to .o
set(ASM_OBJECTS
        wrapper/mat2i.hpp
        wrapper/mat2f.hpp
        wrapper/mat2d.hpp
        wrapper/mat3d.hpp
        wrapper/mat3f.hpp
        wrapper/mat3i.hpp
        wrapper/mat4i.hpp
        wrapper/mat4d.hpp
        wrapper/mat4f.hpp
        wrapper/point2f.hpp
        wrapper/point2d.hpp
        wrapper/point2i.hpp
        wrapper/point3f.hpp
        wrapper/point3d.hpp
        wrapper/point3i.hpp)

foreach(ASM_FILE ${ASM_SOURCES})
    get_filename_component(ASM_NAME ${ASM_FILE} NAME_WE)
    set(OBJ_FILE "${CMAKE_CURRENT_BINARY_DIR}/${ASM_NAME}.o")

    add_custom_command(
            OUTPUT ${OBJ_FILE}
            COMMAND nasm -f elf64 -o ${OBJ_FILE} ${ASM_FILE}
            DEPENDS ${ASM_FILE}
            COMMENT "Assembling ${ASM_NAME}.asm"
    )

    list(APPEND ASM_OBJECTS ${OBJ_FILE})
endforeach()

# Create the shared library
add_library(Kokum SHARED
        ${CPP_SOURCES}
        ${ASM_OBJECTS}
)

# Expose the wrapper headers
target_include_directories(Kokum PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/wrapper
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
