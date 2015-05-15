#JEU	= texte
JEU = graphique
#OS = LINUX
OS  = OSX

ifeq ($(JEU),texte)

OBJ_REP = obj
SRC_REP = src
BIN_REP = bin
LIB = -lncurses
FLAGS = -lm 
DEFINE = -DJEU_NCURSES

all: jeu

jeu: coordonates.o projectile.o enemy.o ensEnemy.o tower.o ensTower.o interface.o map.o gameTxt.o  main.o
	gcc $(OBJ_REP)/coordonates.o $(OBJ_REP)/projectile.o $(OBJ_REP)/enemy.o $(OBJ_REP)/ensEnemy.o $(OBJ_REP)/tower.o $(OBJ_REP)/ensTower.o $(OBJ_REP)/infertace.o $(OBJ_REP)/map.o $(OBJ_REP)/gameTxt.o $(OBJ_REP)/main.o -o $(BIN_REP)/jeu $(FLAGS) $(LIB) $(DEFINE)

coordonates.o: $(SRC_REP)/coordonates.c $(SRC_REP)/coordonates.h
	gcc -c $(SRC_REP)/coordonates.c -o $(OBJ_REP)/coordonates.o

projectile.o: $(SRC_REP)/projectile.c $(SRC_REP)/projectile.h
	gcc -c $(SRC_REP)/projectile.c -o $(OBJ_REP)/projectile.o

enemy.o: $(SRC_REP)/enemy.c $(SRC_REP)/enemy.h $(SRC_REP)/coordonates.h
	gcc -c $(SRC_REP)/enemy.c -o $(OBJ_REP)/enemy.o

ensEnemy.o: $(SRC_REP)/ensEnemy.c $(SRC_REP)/ensEnemy.h
	gcc -c $(SRC_REP)/ensEnemy.c -o $(OBJ_REP)/ensEnemy.o

tower.o: $(SRC_REP)/tower.c $(SRC_REP)/tower.h
	gcc -c $(SRC_REP)/tower.c -o $(OBJ_REP)/tower.o

ensTower.o: $(SRC_REP)/ensTower.c $(SRC_REP)/ensTower.h
	gcc -c $(SRC_REP)/ensTower.c -o $(OBJ_REP)/ensTower.o

interface.o: $(SRC_REP)/interface.c $(SRC_REP)/interface.h $(SRC_REP)/tower.h $(SRC_REP)/map.h
	gcc -c $(SRC_REP)/interface.c -o $(OBJ_REP)/infertace.o

map.o: $(SRC_REP)/map.c $(SRC_REP)/map.o $(SRC_REP)/ensTower.h $(SRC_REP)/ensEnemy.h $(SRC_REP)/coordonates.h
	gcc -c $(SRC_REP)/map.c -o $(OBJ_REP)/map.o

gameTxt.o: $(SRC_REP)/gameTxt.c $(SRC_REP)/gameTxt.h $(SRC_REP)/map.h
	gcc -c $(SRC_REP)/gameTxt.c -o $(OBJ_REP)/gameTxt.o

menu.o: $(SRC_REP)/menu.c $(SRC_REP)/menu.o
	gcc -c $(SRC_REP)/menu.c -o $(OBJ_REP)/menu.o

main.o: $(SRC_REP)/main.c 
	gcc -c $(SRC_REP)/main.c -o $(OBJ_REP)/main.o

regression.o: $(SRC_REP)/regression.c
	gcc -c $(SRC_REP)/regression.c -o $(OBJ_REP)/regression.o

clean:
	rm $(OBJ_REP)/* $(BIN_REP)/* $(SRC_REP)/*.o


else


OBJ_REP = obj
SRC_REP = src
BIN_REP = bin
LIB = -lSDL -lSDL_ttf -lSDL_image

ifeq ($(OS),OSX)
INCLUDES = -I/Library/Frameworks/SDL.framework/Headers osx/SDLmain.m 
LINCLUDES = -framework SDL -framework Cocoa
endif

FLAGS = -lm 

all: jeu

jeu: coordonates.o projectile.o enemy.o ensEnemy.o tower.o ensTower.o interface.o map.o sdlFct.o gameSDL.o menu.o main.o
	gcc $(OBJ_REP)/coordonates.o $(OBJ_REP)/projectile.o $(OBJ_REP)/enemy.o $(OBJ_REP)/ensEnemy.o $(OBJ_REP)/tower.o $(OBJ_REP)/ensTower.o $(OBJ_REP)/infertace.o $(OBJ_REP)/map.o $(OBJ_REP)/sdlFct.o $(OBJ_REP)/gameSDL.o $(OBJ_REP)/menu.o $(OBJ_REP)/main.o -o $(BIN_REP)/jeu $(FLAGS) $(LIB) $(INCLUDES) $(LINCLUDES)

coordonates.o: $(SRC_REP)/coordonates.c $(SRC_REP)/coordonates.h
	gcc -c $(SRC_REP)/coordonates.c -o $(OBJ_REP)/coordonates.o

projectile.o: $(SRC_REP)/projectile.c $(SRC_REP)/projectile.h
	gcc -c $(SRC_REP)/projectile.c -o $(OBJ_REP)/projectile.o

enemy.o: $(SRC_REP)/enemy.c $(SRC_REP)/enemy.h
	gcc -c $(SRC_REP)/enemy.c -o $(OBJ_REP)/enemy.o

ensEnemy.o: $(SRC_REP)/ensEnemy.c $(SRC_REP)/ensEnemy.h
	gcc -c $(SRC_REP)/ensEnemy.c -o $(OBJ_REP)/ensEnemy.o

tower.o: $(SRC_REP)/tower.c $(SRC_REP)/tower.h
	gcc -c $(SRC_REP)/tower.c -o $(OBJ_REP)/tower.o

ensTower.o: $(SRC_REP)/ensTower.c $(SRC_REP)/ensTower.h
	gcc -c $(SRC_REP)/ensTower.c -o $(OBJ_REP)/ensTower.o

interface.o: $(SRC_REP)/interface.c $(SRC_REP)/interface.h
	gcc -c $(SRC_REP)/interface.c -o $(OBJ_REP)/infertace.o

map.o: $(SRC_REP)/map.c $(SRC_REP)/map.h
	gcc -c $(SRC_REP)/map.c -o $(OBJ_REP)/map.o

sdlFct.o: $(SRC_REP)/sdlFct.c $(SRC_REP)/sdlFct.h
	gcc -c $(SRC_REP)/sdlFct.c -o $(OBJ_REP)/sdlFct.o

gameSDL.o: $(SRC_REP)/gameSDL.c $(SRC_REP)/gameSDL.h
	gcc -c $(SRC_REP)/gameSDL.c -o $(OBJ_REP)/gameSDL.o

menu.o: $(SRC_REP)/menu.c $(SRC_REP)/menu.h $(SRC_REP)/sdlFct.h $(SRC_REP)/interface.h
	gcc -c $(SRC_REP)/menu.c -o $(OBJ_REP)/menu.o

main.o: $(SRC_REP)/main.c 
	gcc -c $(SRC_REP)/main.c -o $(OBJ_REP)/main.o $(DEFINE)

regression.o: $(SRC_REP)/regression.c
	gcc -c $(SRC_REP)/regression.c -o $(OBJ_REP)/regression.o

clean:
	rm $(OBJ_REP)/* $(BIN_REP)/* $(SRC_REP)/*.o


endif
