#ifndef GAMESDL_H
#define GAMESDL_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#include "map.h"
#include "interface.h"
#include "sdlFct.h"
#include "menu.h"


typedef struct
{
	Map *map;
	Interface *interface;

	SDL_Surface* surfaceEcran;

	Sprite* Terrain;
	Sprite* Path;
	Sprite* Grotte;
	Sprite* Castle;

	Sprite* TowerAura;
	Sprite* TowerKnight;
	Sprite* TowerArcher;
	Sprite* TowerMage;
	Sprite* TowerCannon;

	Sprite* Life;
	Sprite* Projectile;
	Sprite* EnemyClassic;
	Sprite* EnemyFly;
	Sprite* EnemyBoss;

	Sprite* Cursor;
	Sprite* Range;
	Sprite* InterfaceBackground;

	TTF_Font *police;
	TTF_Font *policeMin;

	int speed;
	int infinityMode;

} sdlMap;

/**
* @brief Initialise une sdlMap
* @param sdMap Pointeur sur sdlMap
*/
void sdlMapInit(sdlMap *sdMap);

/**
* @brief Affiche une sdlMap
* @param sdMap Pointeur sur sdlMap
*/
void sdlMapAff(const sdlMap *sdMap);

/**
* @brief Affiche le terrain
* @param sdMap Pointeur sur sdlMap
*/
void sdlTerrainAff(const sdlMap *sdMap);

/**
* @brief Affiche les ennemies
* @param sdMap Pointeur sur sdlMap
*/
void sdlEnemyAff(const sdlMap *sdMap);

/**
* @brief Affiche les tours
* @param sdMap Pointeur sur sdlMap
*/
void sdlTowerAff(const sdlMap *sdMap);

/**
* @brief Affiche l'interface
* @param sdMap Pointeur sur sdlMap
*/
void sdlInterfaceAff(const sdlMap *sdMap);

/**
* @brief Boucle d'evenement de la sdlMap
* @param sdMap Pointeur sur sdlMap
*/
void sdlMapBoucle(sdlMap *sdMap);

/**
* @brief Libere la sdlMap
* @param sdMap Pointeur sur sdlMap
*/
void sdlMapLibere(sdlMap *sdMap);

/**
* @brief Renvoie le mode de jeu
* @param sdMap Pointeur sur sdlMap
* @return Retourne le mode de jeu
*/
int getSdlMapMode(const sdlMap *sdMap);
/**
* @brief Modifie le mode de jeu
* @param sdMap Pointeur sur sdlMap
* @param mode entier indiquant le mode de jeu
*/
void setSdlMapMode(sdlMap *sdMap, int mode);

/**
* @brief Renvoie la vitesse de fonctionnement du jeu
* @param sdMap Pointeur sur sdlMap
* @return Retourne la vitesse de fonctionnement du jeu
*/
int getSdlMapSpeed(const sdlMap *sdMap);
/**
* @brief Modifie la vitesse de fonctionnement du jeu
* @param sdMap Pointeur sur sdlMap
* @param speed entier indiquant la vitesse de fonctionnement du jeu
*/
void setSdlMapSpeed(sdlMap *sdMap, int speed);

/**
* @brief Renvoie la carte actuelle
* @param sdMap Pointeur sur sdlMap
* @return Retourne la carte actuelle
*/
Map* getSdlMap(const sdlMap *sdMap);
/**
* @brief Modifie la carte actuelle
* @param sdMap Pointeur sur sdlMap
* @param map Pointeur sur Map
*/
void setSdlMap(sdlMap *sdMap, Map *map);

/**
* @brief Renvoie l'interface de jeu
* @param sdMap Pointeur sur sdlMap
* @return Retourne l'interface de jeu
*/
Interface* getSdlMapInterface(const sdlMap *sdMap);
/**
* @brief Modifie l'interface de jeu
* @param sdMap Pointeur sur sdlMap
* @param i Pointeur sur Interface
*/
void setSdlMapInterface(sdlMap *sdMap, Interface *i);

/**
* @brief Renvoie l'écran du jeu
* @param sdMap Pointeur sur sdlMap
* @return Retourne l'écran du jeu
*/
SDL_Surface* getSdlMapEcran(const sdlMap *sdMap);
/**
* @brief Modifie l'écran du jeu
* @param sdMap Pointeur sur sdlMap
* @param i Pointeur sur Interface
*/
void setSdlMapEcran(sdlMap *sdMap, SDL_Surface* ecran);
#endif
