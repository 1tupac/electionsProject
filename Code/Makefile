# Options de Compilation
CC = g++
CCFLAGS = -g
#CCSETTING = --std=c++11 -w -lSDL2 -lSDL2_image -lSDL2_ttf # -lSDL  


CCSETTINGPC = --std=c++11 -Wall -w -lSDL2 -lSDL2_image -lSDL2_ttf # -lSDL
CCSETTINGMAC = --std=c++11 -Wall -w -framework SDL2 -framework SDL2_image -framework SDL2_ttf -DMAC

OS := $(shell uname)
ifeq ($(OS), Darwin)
	CCSETTING = $(CCSETTINGMAC)
else
	CCSETTING = $(CCSETTINGPC)
endif

# fichiers du projet
SRC = point.cc window.cc candidate.cc database.cc chart.cc button.cc buttonElection.cc text.cc main.cc
OBJ = $(SRC:.cc=.o)
EXEC = main.out

# règle initiale
all: $(EXEC)

# dépendance en .h
%.cc : %.hh

# règles de compilation
%o: %cc
	$(CC) $(CCFLAGS) -o $@ -c $< $(CCSETTING)

# édition des liens
$(EXEC): $(OBJ)
	$(CC) -o $@ $^ -lm $(CCSETTING)
	
# règles supplémentaires
clean:
	rm -f *o
	rm -f $(EXEC)
mproper:
	rm -f $(EXEC) *.o
	
.PHONY: all clean mproper

