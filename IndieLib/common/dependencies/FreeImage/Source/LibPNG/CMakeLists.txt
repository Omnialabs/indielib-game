FILE(GLOB SOURCE_FILES
*.c
*.h
)

# Remove some sources with mains
list(REMOVE_ITEM SOURCE_FILES ${CMAKE_CURRENT_LIST_DIR}/pngtest.c)

include_directories(../ZLib)

add_library(png STATIC ${SOURCE_FILES})
target_link_libraries(png zlib)
