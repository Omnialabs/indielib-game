FILE(GLOB SOURCE_FILES
Half/half.*
Iex/*.cpp
IlmImf/Imf*

IlmThread/IlmThread.cpp
IlmThread/IlmThread.h
IlmThread/IlmThreadMutex.cpp
IlmThread/IlmThreadMutex.h
IlmThread/IlmThreadPool.cpp
IlmThread/IlmThreadPool.h
IlmThread/IlmThreadSemaphore.cpp
IlmThread/IlmThreadSemaphore.h
)

if(WIN32)
list(APPEND SOURCE_FILES
IlmThread/IlmThreadMutexWin32.cpp
IlmThread/IlmThreadSemaphoreWin32.cpp
IlmThread/IlmThreadWin32.cpp
)
else()
list(APPEND SOURCE_FILES
IlmThread/IlmThreadMutexPosix.cpp
IlmThread/IlmThreadPosix.cpp
IlmThread/IlmThreadSemaphorePosix.cpp
IlmThread/IlmThreadSemaphorePosixCompat.cpp
)
endif()

include_directories(IlmImf Imath Iex Half IlmThread . ../ZLib)
include_directories(../ZLib)

add_library(openexr STATIC ${SOURCE_FILES})
