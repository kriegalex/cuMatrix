set(srcs)
set(hdrs IMatrix.h)

add_library(core ${srcs} ${hdrs})
# add current dir as include dir for this lib
target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# only if headers only
set_target_properties(core PROPERTIES LINKER_LANGUAGE CXX)