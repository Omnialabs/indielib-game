set(SOURCE_FILES src/glew.c)

include_directories(include)

add_library(glew STATIC ${SOURCE_FILES})
set_target_properties(glew PROPERTIES
 COMPILE_FLAGS -DGLEW_STATIC)