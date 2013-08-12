FILE(GLOB SOURCE_FILES *.cpp *.h)

include_directories(../IndieLib/common/include)

add_executable(Game ${SOURCE_FILES})
target_link_libraries(Game IndieLib)