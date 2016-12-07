
cmake_minimum_required(VERSION 2.8)
project(LightInkMsgPack)

include_directories( ${LightInkMsgPack_SOURCE_DIR}/../../include )

set( sourceRootPath ${LightInkMsgPack_SOURCE_DIR}/../../src )

set( middlePath Common )
set( sourceFile 
	RuntimeError.cpp
	LightInkVersion.cpp
	WinSnprintf.c
)
foreach(k ${sourceFile} )
  set( fullSourcePath ${fullSourcePath} ${sourceRootPath}/${middlePath}/${k} )
endforeach(k)


set( middlePath Msgpack )
set( sourceFile 
	CapCompresser.cpp
	DataBuffer.cpp
	XxteaEncrypter.cpp
)
foreach(k ${sourceFile} )
  set( fullSourcePath ${fullSourcePath} ${sourceRootPath}/${middlePath}/${k} )
endforeach(k)

if (CMAKE_BUILD_TYPE STREQUAL Debug)
	add_definitions("-D_DEBUG")
endif ()
add_definitions("-DLIGHTINK_AS_DLL")
add_definitions("-DLIGHTINK_EXPORTS")

add_library( ${PROJECT_NAME} SHARED ${fullSourcePath} )


if (CMAKE_BUILD_TYPE STREQUAL Debug)
set(LIBRARY_OUTPUT_PATH ${LightInkMsgPack_SOURCE_DIR}/../../bin/Debug)
else()
set(LIBRARY_OUTPUT_PATH ${LightInkMsgPack_SOURCE_DIR}/../../bin/Release)
endif()

unset(middlePath)
unset(sourceFile)
unset(fullSourcePath)
unset(sourceRootPath)






