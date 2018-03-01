GPP=g++

CPPFLAGS=-std=c++11 
PATTERN_DEP = %.cpp %.h 

EDITION_LIEN=$(GPP) $(CPPFLAGS) -o $@ $^
COMPILATION=$(GPP) $(CPPFLAGS) -c -o $@ $<

OBJECTS = lexer.h symbole.h automate.h etat.h e0.h e1.h e2.h e3.h e4.h e5.h e6.h e7.h e8.h e9.h

DIR_COMP=bin
NOM_EXEC=$(DIR_COMP)/app
MAIN=main.cpp

$(NOM_EXEC) : $(MAIN) $(OBJECTS:.h=.o)
	if [ ! -d "$(DIR_COMP)" ]; then mkdir $(DIR_COMP); fi
	$(EDITION_LIEN)
	rm -f *.o

$(OBJECTS:.h=.o): %.o: $(PATTERN_DEP)
	$(COMPILATION)

clean:
	rm -f *.o
	rm $(DIR_COMP)/*
