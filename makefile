GPP=g++

CPPFLAGS=-std=c++11 
PATTERN_DEP = %.cpp %.h 

EDITION_LIEN=$(GPP) $(CPPFLAGS) -o $@ $^
COMPILATION=$(GPP) $(CPPFLAGS) -c -o $@ $<

OBJECTS = lexer.h symbole.h automate.h etat.h expr.h e1.h

DIR_COMP=bin
NOM_EXEC=$(DIR_COMP)/app
MAIN=main.cpp

$(NOM_EXEC) : $(MAIN) $(OBJECTS:.h=.o)
	# Création du dossier des binaires
	if [ ! -d "$(DIR_COMP)" ]; then mkdir $(DIR_COMP); fi
	$(EDITION_LIEN)
	rm -f *.o

$(OBJECTS:.h=.o): %.o: $(PATTERN_DEP)
	$(COMPILATION)

clean:
	rm -f *.o
	rm $(DIR_COMP)/*