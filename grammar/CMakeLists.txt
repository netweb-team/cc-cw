# minimum required CMAKE version
CMAKE_MINIMUM_REQUIRED(VERSION 3.7 FATAL_ERROR)


list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# compiler must be 11 or 14
set(CMAKE_CXX_STANDARD 17)

# set(CMAKE_C_STANDARD 99)
# set(CMAKE_CXX_STANDARD 14)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
# set(CMAKE_C_FLAGS "-g -O0 -Wall -W -fprofile-arcs -ftest-coverage")
# set(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")
# set(CMAKE_C_COMPILER C:/Qt/Tools/mingw810_64/bin/gcc.exe)
# set(CMAKE_CXX_COMPILER "C:/Qt/Tools/mingw810_32/bin/g++.exe")



# required if linking to static library
add_definitions(-DANTLR4CPP_STATIC)

# using /MD flag for antlr4_runtime (for Visual C++ compilers only)
set(ANTLR4_WITH_STATIC_CRT OFF)
# add external build for antlrcpp
include(ExternalAntlr4Cpp)
# add antrl4cpp artifacts to project environment
include_directories(${ANTLR4_INCLUDE_DIRS})

# set variable pointing to the antlr tool that supports C++
# this is not required if the jar file can be found under PATH environment
set(ANTLR_EXECUTABLE /mnt/c/Javalib/antlr-4.10.1-complete.jar)
# add macros to generate ANTLR Cpp code from grammar
find_package(ANTLR REQUIRED)

set(THREADS_PREFER_PTHREAD_FLAG ON)

# Call macro to add lexer and grammar to your build dependencies.
antlr_target(ObjectPascalLexer ObjectPascalLexer.g4 LEXER
             PACKAGE antlrcpptest)
antlr_target(ObjectPascalParser ObjectPascalParser.g4 PARSER
             PACKAGE antlrcpptest
             DEPENDS_ANTLR ObjectPascalLexer
             COMPILE_FLAGS -lib ${ANTLR_ObjectPascalLexer_OUTPUT_DIR})

# include generated files in project environment
include_directories(${ANTLR_ObjectPascalLexer_OUTPUT_DIR})
include_directories(${ANTLR_ObjectPascalParser_OUTPUT_DIR})


project(compiler)
find_package(Threads REQUIRED)
# add generated grammar to demo binary target
add_executable(${PROJECT_NAME} main.cpp libs/ObjectPascalLexer.cpp libs/ObjectPascalParser.cpp
               ${ANTLR_ObjectPascalLexer_CXX_OUTPUTS}
               ${ANTLR_ObjectPascalParser_CXX_OUTPUTS} )
target_link_libraries(${PROJECT_NAME} antlr4_static pthread Threads::Threads)


