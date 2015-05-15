#ifndef INTERFACE_H
#define INTERFACE_H

#include <stdio.h>
#include <stdlib.h>

#include "tower.h"
#include "map.h"

struct sCursor{
	Coord position;
	Coord max;
	Coord min;
};

typedef struct sCursor Cursor;

struct sInterface{

	Tower *tower;
	Cursor *cursor;

};
typedef struct sInterface Interface;

Cursor *newCursor();

/**
* @brief Deplace le curseur vers la gauche
* @param c POinteur sur Cursor
*/
void moveCursorLeft(Cursor *c);

/**
* @brief Deplace le curseur vers la droite
* @param c POinteur sur Cursor
*/
void moveCursorRight(Cursor *c);

/**
* @brief Deplace le curseur vers le haut
* @param c POinteur sur Cursor
*/
void moveCursorUp(Cursor *c);

/**
* @brief Deplace le curseur vers le bas
* @param c POinteur sur Cursor
*/
void moveCursorDown(Cursor *c);

/**
* @brief Initialise une interface
* @param i Pointeur sur une interface
*/
Interface* newInterface();

/**
* @brief Modifie la tower selectionée
* @param i Pointeur sur une interface
* @param t Pointeur sur une tower
*/
void setInterfaceTower(Interface *i,Tower *t);
/**
* @brief Recup la Tower active dans l'interface
* @param i Pointeur sur une interface
* @return La tour selectionnée
*/
Tower *getInterfaceTower(const Interface *i);

/**
* @brief Achete une tower depuis l'interface
* @param type Type de tower à acheter
* @return si ça la fait ou non
*/
int buyInterfaceTower(unsigned char type, Coord *c, Map *map);

/**
* @brief Vend la tour qui est sous le curseur
* @param map Pointeur sur map
* @param c Pointeur sur Coord
* @param t Pointeur sur Tower
*/
int sellInterfaceTower(Map *map, Coord *c, Tower *t);

/**
* @brief Place la tower sur la map
* @param t Pointeur sur une tower
*/
void placeInterfaceTower(Tower *t);

/**
* @brief Est ce que le curseur est sur une tour
* @param c Pointeur sur Cursor
* @param map Pointeur sur Map
*/
int isCursorOnTower(Cursor *c, Map *map);

/**
* @brief Renvoie un pointeur sur la tour qui est sous le curseur
* @param c Pointeur sur Cursor
* @param map Pointeur sur Map
* @return Pointeur sur Tower
*/
Tower *getTowerUnderCursor(Cursor *c, Map *map);

/**
* @brief Met a jour l'interface
* @param i Pointeur sur Interface
* @param map Pointeur sur Map
*/
void updateInterface(Interface *i, Map *map);

/**
* @brief Libère l'interface
* @param i Pointeur sur Interface
*/
void freeInterface(Interface *i);

/**
* @brief Renvoie les caractèristiques du curseur
* @param i Pointeur sur Interface
* @return Pointeur sur Cursor
*/
Cursor *getInterfaceCursor(Interface *i);
/**
* @brief Modifie les caractèristiques du curseur
* @param i Pointeur sur Interface
* @param c Pointeur sur Cursor
*/
void setInterfaceCursor(Interface *i,Cursor *c);

/**
* @brief Renvoie la position du curseur
* @param c Pointeur sur Cursor
* @return Retourne les coordonnées du curseur
*/
Coord getCursorPosition(const Cursor *c);
/**
* @brief Modifie la position du curseur
* @param c Pointeur sur Cursor
* @param coord Pointeur sur Coord
*/
void setCursorPosition(Cursor *c, Coord coord);
#endif