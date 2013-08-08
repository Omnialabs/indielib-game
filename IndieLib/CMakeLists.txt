FILE (GLOB SOURCE_FILES
common/src/*.cpp
common/src/platform/*.cpp
)

#TODO: It seems this is not supported yet, they are not in the SLN build
list(REMOVE_ITEM SOURCE_FILES
${CMAKE_CURRENT_LIST_DIR}/common/src/IND_SpriterEntity.cpp
${CMAKE_CURRENT_LIST_DIR}/common/src/IND_SpriterManager.cpp
${CMAKE_CURRENT_LIST_DIR}/common/src/IND_TmxMapManager.cpp
)

add_subdirectory(common/dependencies)

set(INCLUDE_DIRECTORIES
common
common/include
common/src
)

if(WIN32)
list(APPEND INCLUDE_DIRECTORIES $ENV{DXSDK_DIR}Include)
find_library(D3DX9_LIB d3dx9 $ENV{DXSDK_DIR}/Lib/x86)
find_library(WINSOCK2_LIB Ws2_32)
set(OS_LIBRARIES ${D3DX9_LIB} opengl32 ${WINSOCK2_LIB})

FILE (GLOB SOURCE_FILES_WIN
common/src/render/directx/*
common/src/render/opengl/*
common/src/platform/win32/*.cpp
)
list(APPEND SOURCE_FILES ${SOURCE_FILES_WIN})

endif()

include_directories(${INCLUDE_DIRECTORIES})


add_library(IndieLib SHARED ${SOURCE_FILES})
target_link_libraries(IndieLib
glew
SDL
SDLmain
tinyxml
FreeImageLib
${OS_LIBRARIES}
)

if(CMAKE_COMPILER_IS_GNUCC)
set (OS_COMPILER_FLAGS
"-DINDIELIB_DLLBUILD -DGLEW_STATIC -DFREEIMAGE_LIB"
)
else()
set (OS_COMPILER_FLAGS
"/D INDIELIB_DLLBUILD /D GLEW_STATIC /D FREEIMAGE_LIB"
)
endif()

set_target_properties(IndieLib PROPERTIES
 COMPILE_FLAGS ${OS_COMPILER_FLAGS})
