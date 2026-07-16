function(merge_static_libraries)

    cmake_parse_arguments(ARG
        ""
        "TARGET;OUTPUT_NAME"
        "LIBRARIES"
        ${ARGN}
    )

    if(NOT UNIX)
        message(FATAL_ERROR "Example currently supports Linux/macOS only.")
    endif()

    set(OUTPUT
        ${CMAKE_CURRENT_BINARY_DIR}/lib${ARG_OUTPUT_NAME}.a
    )

    set(SCRIPT ${CMAKE_CURRENT_BINARY_DIR}/merge_${ARG_OUTPUT_NAME}.sh)

    file(WRITE ${SCRIPT}
"#!/bin/sh
set -e

rm -rf merge_tmp
mkdir merge_tmp
cd merge_tmp
")

    foreach(lib ${ARG_LIBRARIES})

        file(APPEND ${SCRIPT}
"
ar x $<TARGET_FILE:${lib}>
")

    endforeach()

    file(APPEND ${SCRIPT}
"
ar rcs ${OUTPUT} *.o
")

    execute_process(
        COMMAND chmod +x ${SCRIPT}
    )

    add_custom_target(
        ${ARG_OUTPUT_NAME}_monolithic
        ALL
        COMMAND ${SCRIPT}
        DEPENDS ${ARG_LIBRARIES}
        COMMENT "Creating monolithic ${OUTPUT}"
    )

endfunction()