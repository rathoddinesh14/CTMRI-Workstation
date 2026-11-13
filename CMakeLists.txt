
cmake_minimum_required(VERSION 3.25)

project(CTMRIWorkstation VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

# Vishwakarma is consumed as a library.
set(VISHWAKARMA_BUILD_SAMPLES OFF CACHE BOOL "" FORCE)
set(VISHWAKARMA_BUILD_TESTS OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    vishwakarma
    GIT_REPOSITORY https://github.com/rathoddinesh14/vishwakarma.git
    GIT_TAG 138ead3f01ad3c8da95a3d02fe380357440e4606
    GIT_SHALLOW FALSE
)

FetchContent_MakeAvailable(vishwakarma)

add_executable(ctmri-workstation
    src/main.cpp
)

target_include_directories(ctmri-workstation
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(ctmri-workstation
    PRIVATE
        Vishwakarma::Graphics
)

if(MSVC)
    target_compile_options(ctmri-workstation PRIVATE /W4)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(ctmri-workstation PRIVATE
        -Wall -Wextra -Wpedantic
    )
endif()

include(CTest)

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
