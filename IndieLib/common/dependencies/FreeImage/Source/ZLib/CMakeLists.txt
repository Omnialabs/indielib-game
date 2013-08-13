FILE(GLOB SOURCE_FILES
*.c
*.h
)

add_library(zlib STATIC ${SOURCE_FILES})
