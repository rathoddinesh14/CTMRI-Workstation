add_executable(ctmri-tests
    test_main.cpp
)

target_compile_features(ctmri-tests PRIVATE cxx_std_20)

set_target_properties(ctmri-tests PROPERTIES
    CXX_EXTENSIONS OFF
)

if(MSVC)
    target_compile_options(ctmri-tests PRIVATE /W4)
else()
    target_compile_options(ctmri-tests PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )
endif()

add_test(
    NAME ctmri-smoke-test
    COMMAND ctmri-tests
)