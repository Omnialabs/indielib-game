FILE(GLOB SOURCE_FILES
*.c
*.h
)

# Remove some sources with mains
list(REMOVE_ITEM SOURCE_FILES ${CMAKE_CURRENT_LIST_DIR}/t1_generate_luts.c)

add_library(openjpeg STATIC ${SOURCE_FILES})

if(CMAKE_COMPILER_IS_GNUCC)
set (OS_COMPILER_FLAGS
"-DOPJ_STATIC"
)
else()
set (OS_COMPILER_FLAGS
"/D OPJ_STATIC"
)
endif()

set_target_properties(openjpeg PROPERTIES
 COMPILE_FLAGS ${OS_COMPILER_FLAGS})