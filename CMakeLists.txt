cmake_minimum_required(VERSION 3.10)

project("MySQL Dump To Neo4J")

add_executable(Experiment lexer/Lexer.cc source/SourceBuffer.cpp source/SourceBuffer.h main.cpp)

# Copy test file into CMake binary build (Copy file only once at the first time)
#file(COPY lexer/test DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# Use this instead file if test file sometime changed
#configure_file(lexer/test test COPYONLY)
#configure_file(lexer/idwiki-20220901-page.sql idwiki-20220901-page.sql COPYONLY)