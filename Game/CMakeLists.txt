FILE(GLOB_RECURSE SOURCE_FILES *.cpp)

include_directories(../IndieLib/common/include)

add_executable(Game ${SOURCE_FILES})
target_link_libraries(Game IndieLib)