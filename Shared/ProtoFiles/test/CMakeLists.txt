set(exe_name ProtoFilesTest)

find_package(Qt5 COMPONENTS Core Network REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(${exe_name}_deps ProtoFiles Qt5::Core Qt5::Network)

set(${exe_name}_srcs
  ProtoFilesTestMain.cpp
  )
source_group("" FILES ${${exe_name}_srcs})
#list(APPEND ${exe_name}_proto_srcs ${${exe_name}_srcs})


add_executable(${exe_name} ${${exe_name}_srcs})
target_link_libraries( ${exe_name} ${${exe_name}_deps})
add_test(NAME ${exe_name} COMMAND ${exe_name})
qt5_use_modules(${exe_name} Widgets Core Test)

set_property(TARGET ${exe_name} PROPERTY FOLDER ${folder}/UnitTests)
