FILE(GLOB SOURCE_FILES
j*.c
*.h
)

# Remove some sources with mains
list(REMOVE_ITEM SOURCE_FILES ${CMAKE_CURRENT_LIST_DIR}/jmemdos.c)
list(REMOVE_ITEM SOURCE_FILES ${CMAKE_CURRENT_LIST_DIR}/jmemmac.c)
list(REMOVE_ITEM SOURCE_FILES ${CMAKE_CURRENT_LIST_DIR}/jpegtran.c)
list(APPEND SOURCE_FILES transupp.c transupp.h)

add_library(jpeg STATIC ${SOURCE_FILES} )
