cmake_minimum_required(VERSION 3.18.4)

set(UA_PARSER_TARGET_NAME ua_parser)

set(UA_PARSER_SOURCES
	src/ua_parser.cpp
)

# Options

set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)
set(CMAKE_BUILD_TYPE Release)



# Lib

project(
	${UA_PARSER_TARGET_NAME}
	VERSION 1.0.0
	LANGUAGES CXX
)

add_library(${PROJECT_NAME} STATIC ${UA_PARSER_SOURCES})

set_target_properties(${PROJECT_NAME}
	PROPERTIES
	CXX_STANDARD 20
	CXX_EXTENSIONS OFF
)

target_include_directories(${PROJECT_NAME} PUBLIC
	$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/inc>
)



# Bin

project(
	${UA_PARSER_TARGET_NAME}-bin
	LANGUAGES CXX
	VERSION 1.0.0
)

add_executable(${PROJECT_NAME} src/main.cpp ${UA_PARSER_SOURCES})

set_target_properties(${PROJECT_NAME}
	PROPERTIES
	CXX_STANDARD 20
	CXX_EXTENSIONS off
	OUTPUT_NAME ${UA_PARSER_TARGET_NAME}
)

target_include_directories(${PROJECT_NAME} PRIVATE
	$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/inc>
)
