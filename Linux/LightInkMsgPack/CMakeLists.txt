
cmake_minimum_required(VERSION 2.8)
project(LightInkMsgPack)

include_directories( ${LightInkMsgPack_SOURCE_DIR}/../../include )

set( sourceRootPath ${LightInkMsgPack_SOURCE_DIR}/../../src )

set( middlePath Common )
set( sourceFile 
	LightInkVersion.cpp
	RuntimeError.cpp
	SmallObject.cpp
	WinSnprintf.c
)
foreach(k ${sourceFile} )
  set( fullSourcePath ${fullSourcePath} ${sourceRootPath}/${middlePath}/${k} )
endforeach(k)


set( middlePath Msgpack )
set( sourceFile 
	DataBuffer.cpp
	DataRefBuffer.cpp
	encrypter/CapCompresser.cpp
	encrypter/XxteaEncrypter.cpp
	encrypter/Crc32Encrypter.cpp
)
foreach(k ${sourceFile} )
  set( fullSourcePath ${fullSourcePath} ${sourceRootPath}/${middlePath}/${k} )
endforeach(k)

if (CMAKE_BUILD_TYPE STREQUAL Release)
	add_definitions("-DNDEBUG")
else ()
	add_definitions("-D_DEBUG")
	set( CMAKE_BUILD_TYPE Debug )
endif ()

add_definitions("-DLIGHTINK_AS_DLL")
add_definitions("-DLIGHTINK_EXPORTS")

add_library( ${PROJECT_NAME} SHARED ${fullSourcePath} )


if (CMAKE_BUILD_TYPE STREQUAL Debug)
set(LIBRARY_OUTPUT_PATH ${LightInkMsgPack_SOURCE_DIR}/../../bin/Debug)
else()
set(LIBRARY_OUTPUT_PATH ${LightInkMsgPack_SOURCE_DIR}/../../bin/Release)
endif()

if (CMAKE_BUILD_TYPE STREQUAL Debug)
set(LIBRARY_OUTPUT_PATH ${LightInkMsgPack_SOURCE_DIR}/../../bin/Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb -W -pipe -fPIC")
else()
set(LIBRARY_OUTPUT_PATH ${LightInkMsgPack_SOURCE_DIR}/../../bin/Release)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -W -pipe -fPIC")
endif()

unset(middlePath)
unset(sourceFile)
unset(fullSourcePath)
unset(sourceRootPath)






