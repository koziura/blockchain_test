# cmake build script
cmake_minimum_required(VERSION 2.8)
project(blockchain_test)

# Add CMake modules directory
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMakeModules/")

#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
#set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

set (CMAKE_CXX_STANDARD 14)

#set(CMAKE_CXX_COMPILER clang++)
#set(CMAKE_C_COMPILER clang)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

if (NOT CMAKE_BUILD_TYPE)
set(CMAKE_BUILD_TYPE MINSIZEREL)
endif (NOT CMAKE_BUILD_TYPE)

# Precompiled header module
include(PrecompiledHeader)

# Headers
set(BLCH_HEADERS
	include/transaction.h
	include/block.h
	include/blockchain.h
	include/baserefs.h
)

# Headers 
set(BLCH_SOURCES
	src/main.cpp
	src/transaction.cpp
	src/block.cpp
	src/blockchain.cpp
)

# Common libraries
set(BLCH_LIBS ssl crypto)

# Additional libraries
set(BLCH_LIBS ${BLCH_LIBS})

# specific definitions
add_definitions(-D__STDC_CONSTANT_MACROS)

# Add include direcories
include_directories(include)
#include_directories(${PROJECT_SOURCE_DIR})

# Add platform-specific inlude direcories
if(UNIX)
  include_directories(${CMAKE_BINARY_DIR}/include)
  link_directories(${CMAKE_BINARY_DIR}/lib)
  # Dependencies project
#  add_subdirectory(3rdparty)
elseif(WIN32)
  include_directories(${PROJECT_SOURCE_DIR}/3rdparty/include)
  link_directories(${PROJECT_SOURCE_DIR}/3rdparty/lib)
endif(UNIX)

# Add vgrabber executable 
add_executable(${PROJECT_NAME} ${BLCH_OPTIONS} ${BLCH_HEADERS} ${BLCH_SOURCES} )
target_link_libraries(${PROJECT_NAME} ${BLCH_LIBS})

#message("< ${CMAKE_PROJECT_NAME} / ${PROJECT_NAME} / ${PROJECT_SOURCE_DIR}")

# Add dependencies
#if(UNIX)
#  add_dependencies(${PROJECT_NAME} ftplib ffmpeg v2u_lib)
#add_dependencies(${PROJECT_NAME})
#endif(UNIX)

# Set up precompiled header
add_precompiled_header(${PROJECT_NAME} include/baserefs.h FORCEINCLUDE)
