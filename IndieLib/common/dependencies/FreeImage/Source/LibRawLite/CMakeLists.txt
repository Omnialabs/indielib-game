FILE(GLOB SOURCE_FILES
internal/*.cpp
internal/*.h
libraw/*
src/*
)

include_directories(.)
if(WIN32)
if(CMAKE_COMPILER_IS_GNUCC)
set (OS_COMPILER_FLAGS
"-DLIBRAW_NODLL -D_WIN32_WINNT=0x0500"
)
else()
set (OS_COMPILER_FLAGS
"/DLIBRAW_NODLL"
)
endif()
endif()

add_library(raw STATIC ${SOURCE_FILES})

if(WIN32)
set_target_properties(raw PROPERTIES
 COMPILE_FLAGS ${OS_COMPILER_FLAGS})
endif()
