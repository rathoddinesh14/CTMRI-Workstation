cmake_minimum_required(VERSION 3.21)

project(CTMRIWorkstation VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(ctmri-workstation
    src/main.cpp
)

target_include_directories(ctmri-workstation
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if(MSVC)
    target_compile_options(ctmri-workstation PRIVATE /W4)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(ctmri-workstation PRIVATE -Wall -Wextra -Wpedantic)
endif()

include(CTest)

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()