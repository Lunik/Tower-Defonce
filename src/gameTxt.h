#ifndef GAMETXT_H
#define GAMETXT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <assert.h>

#include "map.h"
#include "interface.h"

struct sGame{
	Map map;
};
typedef struct sGame Game;

/**
@brief boucle d'evenement
@param map Pointeur sur map
*/
void ncursBoucle(Map *map);

/**
@brief affichage  ncurses
@param win Pointeur sur WINDOW
@param map Pointeur sur map
*/
void ncursAff(WINDOW* win, const Map *map);

#endif
