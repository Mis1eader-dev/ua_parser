cmake_minimum_required(VERSION 3.22.1)

set(UA_PARSER_SOURCES
	src/ua_parser.cpp
)
set(UA_PARSER_HEADER
	inc/ua_parser/ua_parser.hpp
)



# Bin

project(
	ua_parser_bin
	LANGUAGES CXX
	VERSION 1.0.0
)

add_executable(${PROJECT_NAME} src/main.cpp ${UA_PARSER_SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE
	$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/inc>
)

set_target_properties(${PROJECT_NAME}
	PROPERTIES
	CXX_STANDARD 20
	CXX_EXTENSIONS off
)



# Lib

project(
	ua_parser
	LANGUAGES CXX
	VERSION 1.0.0
)

add_library(${PROJECT_NAME} STATIC ${UA_PARSER_SOURCES} ${UA_PARSER_HEADER})

target_include_directories(${PROJECT_NAME} PUBLIC
	$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/inc>
)

set_target_properties(${PROJECT_NAME}
	PROPERTIES
	CXX_STANDARD 20
	CXX_EXTENSIONS off
)
