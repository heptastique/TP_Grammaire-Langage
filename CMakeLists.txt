cmake_minimum_required (VERSION 2.6)
set(CMAKE_CXX_STANDARD 11)

project (TP_Grammaire-Langage)


set(SOURCES
        main.cpp
        lexer.cpp
        symbole.cpp
        automate.cpp
        etat.cpp
	e0.cpp
        e1.cpp
	e2.cpp
	e3.cpp
	e4.cpp
	e5.cpp
	e6.cpp
	e7.cpp
	e8.cpp
	e9.cpp
        expr.cpp)

set(HEADERS
        lexer.h
        symbole.h
        automate.h
        etat.h
        e0.h
	e1.h
        e2.h
        e3.h
        e4.h
        e5.h
        e6.h
        e7.h
        e8.h
        e9.h
        expr.h)


add_executable(TP ${SOURCES} ${HEADERS})
