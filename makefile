DEBUG=yes
GPP=g++
GFLAGS=-std=c++11 

EXEC=TPLG
SRC= $(wildcard *.cpp)
HEAD= $(filter-out debug.h, $(wildcard *.h))
OBJ= $(filter-out main.o, HEAD:.cpp=.o)
MAIN=main.cpp

all: $(EXEC)

ifeq ($(DEBUG),yes)
	CFLAGS=-g
	LDFLAGS=-g
else
	CFLAGS=
	LDFLAGS=
endif

ifeq ($(DEBUG),yes)
	@echo "Génération en mode debug"
else
	@echo "Génération en mode release"
endif

$(EXEC) : $(MAIN) $(HEAD:.h=.o)
	$(GPP) $(GFLAGS) -o $@ $^ $(LDFLAGS)

$(HEAD:.h=.o): %.o: %.cpp %.h
	$(GPP) $(GFLAGS) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o
	
mrproper: clean
	@rm -rf $(EXEC)
