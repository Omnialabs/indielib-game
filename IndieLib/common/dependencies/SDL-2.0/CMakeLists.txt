FILE (GLOB SOURCE_FILES
src/*
src/audio/disk/*
src/audio/dummy/*
src/audio/SDL_*
src/atomic/*
src/cpuinfo/*
src/events/SDL_*
src/file/SDL_*
src/haptic/*
src/joystick/*
src/libm/*
src/power/*
src/render/*
src/render/software/*
src/stdlib/*
src/thread/*
src/timer/*
src/video/*
src/video/dummy/*
)


set(INCLUDE_DIRECTORIES include)

######## WINDOWS ########

if(WIN32)

FILE (GLOB SOURCE_FILES_WIN
src/audio/directsound/*
src/audio/winmm/*.c
src/audio/xaudio2/*.c
src/core/windows/*
src/haptic/windows/*
src/joystick/windows/*
src/loadso/windows/*
src/power/windows/*
src/render/direct3d/*
src/render/opengl/*
src/thread/windows/SDL_*
src/timer/windows/*
src/video/windows/*
)
list(APPEND SOURCE_FILES ${SOURCE_FILES_WIN})

set(SOURCE_FILES_MAIN
src/main/windows/SDL_windows_main.c
)

list(APPEND INCLUDE_DIRECTORIES $ENV{DXSDK_DIR}Include)

if(CMAKE_COMPILER_IS_GNUCC)

#sal.h doesn't seem to exist in MinGW headers so use the one that comes with VS 2008/express. We
#copy the header instead of adding VC/Include because that would conflict with the MinGW headers.
set(COPY_SRC $ENV{VS90COMNTOOLS}../../VC/Include/sal.h)
set(COPY_DST ${CMAKE_CURRENT_BINARY_DIR}/sal.h)

EXECUTE_PROCESS(COMMAND  ${CMAKE_COMMAND} -E copy ${COPY_SRC} ${COPY_DST}
         RESULT_VARIABLE resultado
         ERROR_VARIABLE erro )

list(APPEND INCLUDE_DIRECTORIES ${CMAKE_CURRENT_BINARY_DIR})
endif()

set(LIBRARIES winmm imm32 version)

endif(WIN32)

######## LINUX ########

if(UNIX AND NOT APPLE)

FILE (GLOB SOURCE_FILES_LINUX
src/haptic/linux/*
src/render/opengl/*
src/timer/unix/*
src/thread/pthread/*
src/joystick/linux/*
src/power/linux/*
src/audio/pulseaudio/*
src/loadso/dlopen/*
src/audio/dsp/*
src/video/x11/*
)
list(APPEND SOURCE_FILES ${SOURCE_FILES_LINUX})

endif()

include_directories(${INCLUDE_DIRECTORIES})

add_library(SDL SHARED ${SOURCE_FILES})
target_link_libraries(SDL ${LIBRARIES})

if(WIN32)
add_library(SDLmain STATIC ${SOURCE_FILES_MAIN})
endif()