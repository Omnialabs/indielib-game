FILE(GLOB SOURCE_FILES *.cpp *.h)

include_directories(../IndieLib/common/include)

if(APPLE)
set_source_files_properties(WorkingPath.cpp PROPERTIES COMPILE_FLAGS -ObjC++)
endif()

add_executable(Game ${SOURCE_FILES})
target_link_libraries(Game IndieLib)