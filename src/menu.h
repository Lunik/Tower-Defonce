#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#include "sdlFct.h"
#include "interface.h"

struct sMenu{

	Cursor *cursor;
	SDL_Surface* surfaceEcran;

	Sprite *Background;
	Sprite *Title;

	Sprite *Cursor;
	Sprite *Button;

	TTF_Font *police;
	TTF_Font *policeMin;

	int helpAff;
	int cinematique;
};
typedef struct sMenu Menu;

/**
* @brief Initialise un menu
* @param menu Pointeur sur Menu
* @param surfaceEcran Pointeur sur l'écran SDL_Surface
*/
void sdlMenuInit(Menu *menu,SDL_Surface *surfaceEcran);

/**
* @brief Affiche un menu
* @param menu Pointeur sur Menu
*/
void sdlMenuAff(Menu *menu);

/**
* @brief Boucle d'evenement du menu
* @param menu Pointeur sur Menu
*/
int sdlMenuBoucle(Menu *menu);

/**
* @brief Libere le menu
* @param menu Pointeur sur Menu
*/
void sdlMenuLibere(Menu *menu);

void cinematique(SDL_Surface *ecran);

#endif
