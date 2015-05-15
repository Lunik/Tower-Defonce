#ifndef MAP_H
#define MAP_H

#include <stdlib.h>
#include <stdio.h>

#include "ensTower.h"
#include "ensEnemy.h"
#include "coordonates.h"

struct sCell{
	Tower *entity;
	int build;
	int path;
	int beginP;
	int endP;
	Coord position;
};
typedef struct sCell Cell;

struct sMap{
	EnsEnemy *enemys;
	EnsTower *towers;
	int dimX;
	int dimY;
	Cell *grid[255][255];
	Coord *path[255];
	int pathCount;
	Coord *start;
	Coord *end;
	int life;
	int wave;
	int gold;
};
typedef struct sMap Map;

/**
* @brief Crée une map
* @param dimX entier indiquant la dimention en X de la carte
* @param dimY entier indiquant la dimention en Y de la carte
* @return Retourne un Pointeur sur Map
*/
Map *newMap(int dimX, int dimY);

/**
* @brief Cree une cellule
* @param build Cellule constructible (bool)
* @param path Cellule sur le chemin (bool)
* @return Pointeur sur une cellule
*/
Cell *newMapCell(int build,int path);

/**
* @brief Initialise une map
* @param Pointeur sur Map
*/
void initMap(Map *map);

/**
* @brief Met à jour la structure map et appel les sous fonctions update
* @param map Pointeur sur Map
*/
void updateMap(Map *map);

/**
* @brief Met un structure dans une cellule
* @param grid Pointeur sur tableau de Cell
* @param x La coord x de la cellule
* @param y La coord y de la cellule
* @param e Pointeur sur une structure
*/
void setMapCell(Cell *grid[255][255], int x, int y, void *e);

/**
* @brief Affiche la map
* @param map Pointeur sur Map
*/
void afficheMap(Map *map);

/**
* @brief Crée une nouvelle vague d'enemies
* @param map Pointeur sur Map
*/
void newWave(Map *map);

/**
* @brief Vérifie les enemies de la vague sont mort
* @param map Pointeur sur Map
*/
int isWaveEnd(Map *map);

/**
* @brief Trouve la cellule de coordonne x,y
* @param map Pointeur sur Map
* @param x La coord x de la cellule
* @param y La coord y de la cellule
* @return Pointeur sur Cell
*/
Cell *getCellFromXY(Map *map, int x, int y);

/**
* @brief Vérifie si la cellule est constructible
* @param c Pointeur sur cell
*/
int isCellBuildable(Cell *c);

/**
* @brief Initialise le chemin pour chaque ennemi
* @param enemys Pointeur sur ensEnemy
* @param path Tableau contenant le path
* @param pathCount Nombre de cases dans le chemin
*/
void initEnemyPath(EnsEnemy *enemys, Coord *path[255], int pathCount);

/**
* @brief Libère la map et tout ses sous structures
* @param map Pointeur sur Map
*/
void freeMap(Map *map);

/**
* @brief Met les ennemis sur la carte
* @param map Pointeur sur Map
* @param enemys Pointeur sur EnsEnemy
*/
void setMapEnemys(Map *map, EnsEnemy *enemys);
/**
* @brief Renvoie les ennemis de la carte
* @param map Pointeur sur Map
* @return Retourne les ennemis de la carte
*/
EnsEnemy* getMapEnemys(const Map *map);

/**
* @brief Met les tours sur la carte
* @param map Pointeur sur Map
* @param towers Pointeur sur EnsTower
*/
void setMapTowers(Map *map, EnsTower *towers);
/**
* @brief Renvoie les tours de la carte
* @param map Pointeur sur Map
* @return Retourne les tours de la carte
*/
EnsTower* getMapTowers(const Map *map);

/**
* @brief Met les dimentions sur la carte
* @param map Pointeur sur Map
* @param x entier indiquant la dimention en X de la carte
* @param y entier indiquant la dimention en Y de la carte
*/
void setMapDim(Map *map, int x, int y);
/**
* @brief Renvoie les dimentions de la carte
* @param map Pointeur sur Map
* @return Retourne les dimentions de la carte
*/
Coord getMapDim(const Map *map);

/**
* @brief Modifie le nombre de case du chemin
* @param map Pointeur sur Map
* @param pathCount entier indiquant le nombre de case du chemin
*/
void setMapPathCount(Map *map, int pathCount);
/**
* @brief Renvoie le nombre de case du chemin
* @param map Pointeur sur Map
* @return Retourne le nombre de case du chemin
*/
int getMapPathCount(const Map *map);

/**
* @brief Modifie les coordonnées de la case de départ du chemin
* @param map Pointeur sur Map
* @param c Pointeur sur Coord
*/
void setMapStart(Map *map, Coord *c);
/**
* @brief Renvoie la case de départ du chemin
* @param map Pointeur sur map
* @return Retourne les coordonnées de la case de départ du chemin
*/
Coord getMapStart(const Map *map);

/**
* @brief Modifie les coordonnées de la case d'arrivée du chemin
* @param map Pointeur sur Map
* @param c Pointeur sur Coord
*/
void setMapEnd(Map *map, Coord *c);
/**
* @brief Renvoie la case d'arrivée du chemin
* @param map Pointeur sur map
* @return Retourne les coordonnées de la case d'arrivée du chemin
*/
Coord getMapEnd(const Map *map);

/**
* @brief Modifie l'affichage de la vie
* @param map Pointeur sur Map
* @param life entier indiquant la quantité de vie restante
*/
void setMapLife(Map *map, int life);
/**
* @brief Renvoie l'affichage de la vie
* @param map Pointeur sur map
* @return Retourne l'affichage de la vie
*/
int getMapLife(const Map *map);

/**
* @brief Modifie l'affichage de la vague actuelle
* @param map Pointeur sur Map
* @param wave entier indiquant la vague
*/
void setMapWave(Map *map, int wave);
/**
* @brief Renvoie l'affichage de la vague
* @param map Pointeur sur map
* @return Retourne l'affichage de la vague
*/
int getMapWave(const Map *map);

/**
* @brief Modifie l'affichage de l'argent restant
* @param map Pointeur sur Map
* @param gold entier indiquant l'argent restant
*/
void setMapGold(Map *map, int gold);
/**
* @brief Renvoie l'affichage de l'argent restant
* @param map Pointeur sur map
* @return Retourne l'affichage de l'argent restant
*/
int getMapGold(const Map *map);

/**
* @brief Modifie l'entité présente sur la case sélectionnée
* @param c Pointeur sur Cell
* @param tower Pointeur sur Tower
*/
void setCellEntity(Cell *c, Tower *tower);
/**
* @brief Renvoie l'entité présente sur la case sélectionnée
* @param c Pointeur sur Cell
* @return Retourne l'entité présente sur la case sélectionnée
*/
Tower *getCellEntity(const Cell *c);

/**
* @brief Modifie si la case sélectionnée est libre pour la construction d'une tour
* @param c Pointeur sur Cell
* @param build entier indiquant si la case sélectionnée est libre
*/
void setCellBuild(Cell *c, int build);
/**
* @brief Vérifie si la case sélectionnée est libre pour la construction d'une tour
* @param c Pointeur sur Cell
* @return Retourne si la case sélectionnée est libre pour la construction d'une tour
*/
int getCellBuild(const Cell *c);

/**
* @brief Modifie si la case fait parti du chemin
* @param c Pointeur sur Cell
* @param path entier indiquant le chemin
*/
void setCellPath(Cell *c, int path);
/**
* @brief Renvoie si la case fait parti du chemin
* @param c Pointeur sur Cell
* @return Retourne si la case fait parti du chemin
*/
int getCellPath(const Cell *c);

/**
* @brief Modifie si la case est la case de départ
* @param c Pointeur sur Cell
* @param begin entier indiquant si la case est la case de départ
*/
void setCellBegin(Cell *c, int begin);
/**
* @brief Renvoie si la case est la case de départ
* @param c Pointeur sur Cell
* @return Retourne si la case est la case de départ
*/
int getCellBegin(const Cell *c);

/**
* @brief Modifie si la case est la case d'arrivée
* @param c Pointeur sur Cell
* @param end entier indiquant si la case est la case d'arrivée
*/
void setCellEnd(Cell *c, int end);
/**
* @brief Renvoie si la case est la case d'arrivée
* @param c Pointeur sur Cell
* @return Retourne si la case est la case d'arrivée
*/
int getCellEnd(const Cell *c);

/**
* @brief Modifie la position en X, Y de la case
* @param c Pointeur sur Cell
* @param pos Pointeur sur Coord
*/
void setCellPosition(Cell *c, Coord *pos);
/**
* @brief Renvoie la position en X, Y de la case
* @param c Pointeur sur Cell
* @return Retourne la position en X, Y de la case
*/
Coord getCellPosition(const Cell *c);

#endif