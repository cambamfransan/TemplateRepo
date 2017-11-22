set(exe_name Playground)

FIND_PACKAGE(Boost COMPONENTS system REQUIRED)
if(Boost_FOUND)
message(STATUS "Found Boost")
endif()
set(${exe_name}_deps ${Boost_LIBRARIES})

set(${exe_name}_srcs
  main.cpp
  )

source_group("" FILES ${${exe_name}_srcs})


add_executable(${exe_name} ${${exe_name}_srcs})
target_link_libraries(${exe_name} ${${exe_name}_deps})
set_property(TARGET ${exe_name} PROPERTY FOLDER ${folder})

message(STATUS "Setting up BOOST")
message(STATUS " Includes - ${Boost_INCLUDE_DIRS}")
message(STATUS " Library  - ${Boost_LIBRARY_DIRS}")
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})


install(TARGETS ${exe_name} DESTINATION bin)
