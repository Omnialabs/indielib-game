FILE(GLOB_RECURSE SOURCE_FILES
Source/FreeImage/*.cpp
Source/FreeImage/*.c
Source/FreeImage/*.h
Source/FreeImageToolkit/*
Source/Metadata/*
)

include_directories(
Source
Source/OpenEXR/Half
Source/OpenEXR/Iex
Source/OpenEXR/IlmImf
Source/OpenEXR/Imath
Source/OpenEXR/IlmThread
)

add_subdirectory(Source/LibJPEG)
add_subdirectory(Source/LibOpenJPEG)
add_subdirectory(Source/LibPNG)
add_subdirectory(Source/ZLib)
add_subdirectory(Source/LibRawLite)
add_subdirectory(Source/LibTIFF4)
add_subdirectory(Source/OpenEXR)

add_library(FreeImageLib STATIC ${SOURCE_FILES})
target_link_libraries(FreeImageLib
jpeg
openjpeg
png
raw
tiff4
openexr
)

if(MSVC)
set (OS_COMPILER_FLAGS
"/D OPJ_STATIC /D FREEIMAGE_LIB /D LIBRAW_NODLL"
)
else()
set (OS_COMPILER_FLAGS
"-DOPJ_STATIC -DFREEIMAGE_LIB -DLIBRAW_NODLL"
)
endif()

set_target_properties(FreeImageLib PROPERTIES
 COMPILE_FLAGS ${OS_COMPILER_FLAGS})