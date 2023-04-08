cmake_minimum_required(VERSION 3.22.1)

project(ua_parser)

set(UA_PARSER_SOURCES
	src/ua_parser.cpp
)

add_executable(ua_parser_bin src/main.cpp ${UA_PARSER_SOURCES})

add_library(${PROJECT_NAME} STATIC ${UA_PARSER_SOURCES})

set_target_properties(${PROJECT_NAME}
	PROPERTIES
	CXX_STANDARD 20
	CXX_EXTENSIONS off
)
