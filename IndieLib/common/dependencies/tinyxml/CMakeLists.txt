FILE(GLOB SOURCE_FILES
*
)

add_library(tinyxml STATIC ${SOURCE_FILES})
