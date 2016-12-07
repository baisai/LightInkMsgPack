
cmake_minimum_required(VERSION 2.8)
PROJECT(Example)

include_directories( ${Example_SOURCE_DIR}/../../Example/include 
					${Example_SOURCE_DIR}/../../include )

set( sourceRootPath ${Example_SOURCE_DIR}/../../Example/src )


set( sourceFile 
	Main.cpp
	CompressEncrypt.cpp
	PackClass.cpp
	PackType.cpp
)
foreach(k ${sourceFile} )
  set( fullSourcePath ${fullSourcePath} ${sourceRootPath}/${k} )
endforeach(k)


if (CMAKE_BUILD_TYPE STREQUAL Debug)
	add_definitions("-D_DEBUG")
endif ()
add_definitions("-DLIGHTINK_AS_DLL")

add_executable( ${PROJECT_NAME} ${fullSourcePath} )

add_dependencies(${PROJECT_NAME} LightInkMsgPack)

target_link_libraries(${PROJECT_NAME} LightInkMsgPack )

if (CMAKE_BUILD_TYPE STREQUAL Debug)
set(EXECUTABLE_OUTPUT_PATH ${Example_SOURCE_DIR}/../../bin/Debug)
else()
set(EXECUTABLE_OUTPUT_PATH ${Example_SOURCE_DIR}/../../bin/Release)
endif()

unset(sourceFile)
unset(fullSourcePath)
unset(sourceRootPath)


