set(lib_name Lib)

set(${lib_name}_deps)

set(${lib_name}_srcs
	SharedFunctions.cpp
	SharedFunctions.hpp
  )

source_group("" FILES ${${lib_name}_srcs})

add_library(${lib_name} ${${lib_name}_srcs})
target_link_libraries(${lib_name} ${${lib_name}_deps})
set_property(TARGET ${lib_name} PROPERTY FOLDER ${folder})
