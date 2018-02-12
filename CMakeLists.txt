cmake_minimum_required (VERSION 2.6)
set(CMAKE_CXX_STANDARD 11)

project (TP_Grammaire-Langage)


set(SOURCES
        main.cpp
        lexer.cpp
        symbole.cpp
        )

set(HEADERS
        lexer.h
        symbole.h
        )


add_executable(TP ${SOURCES} ${HEADERS})
