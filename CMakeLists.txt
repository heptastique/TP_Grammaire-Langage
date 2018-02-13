cmake_minimum_required (VERSION 2.6)
set(CMAKE_CXX_STANDARD 11)

project (TP_Grammaire-Langage)


set(SOURCES
        main.cpp
        lexer.cpp
        symbole.cpp
        automate.cpp
        etat.cpp
        e1.cpp
        expr.cpp)

set(HEADERS
        lexer.h
        symbole.h
        automate.h
        etat.h
        e1.h
        expr.h)


add_executable(TP ${SOURCES} ${HEADERS})
