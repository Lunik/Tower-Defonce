#include <stdio.h>
#include <stdlib.h>

//#define JEU_NCURSES

#define JEU_SDL

#ifdef JEU_NCURSES
#include "gameTxt.h"
#endif

#ifdef JEU_SDL
#include "gameSDL.h"
#endif

int main ( int argc, char** argv )
{
	
    #ifdef JEU_NCURSES
    printf("TD Ncurses\n");
    Map *map;
	map = newMap(15,15);
        ncursBoucle(map);
    #endif
    
    #ifdef JEU_SDL
        printf("TD SDL\n");
    
        sdlMap sdMap;
        sdlMapInit( &sdMap );
        sdlMapBoucle( &sdMap );
        sdlMapLibere( &sdMap );
    #endif
    
    return 0;
}
