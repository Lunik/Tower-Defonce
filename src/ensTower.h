#ifndef ENSTOWER_H
#define ENSTOWER_H

#include "tower.h"
#include "ensEnemy.h"

struct sEnsTower{
	Tower *tab[1000];
	int nb;
};
typedef struct sEnsTower EnsTower;

EnsTower *newEnsTower();

/**
* @brief Ajoute une tour dans l'ensemble des tours
* @param towers Pointeur sur EnsTower
* @param t Pointeur sur Tower
*/
void addEnsTower(EnsTower *towers,Tower *t);

/**
* @brief Supprime la tour sélectionnée
* @param towers Pointeur sur EnsTower
* @param t Pointeur sur Tower
*/
void removeEnsTower(EnsTower *towers,Tower *t);

/**
* @brief Réalise les modifications liées à l'achat d'une tour si on a assez de "gold"
* @param towers Pointeur sur EnsTower
* @param type caractère indiquant le type de la tour
* @param posX entier indiquant la position en X de la tour
* @param posY entier indiquant la position en Y de la tour
* @param gold Pointeur indiquant la quantité de "gold" restant
* @return Retourne si la tour a été achetée
*/
int buyTower(EnsTower **towers, unsigned char type, int posX, int posY, int *gold);

/**
* @brief Vend la tour sélectionnée
* @param towers Pointeur sur EnsTower
* @param t Pointeur sur Tower
*/
void sellTower (EnsTower *towers, Tower *t);

/**
* @brief Gére les intéractions entre une tower et les Ennemies
* @param t Pointeur sur Tower
* @param enemys Pointeur sur EnsEnemy
*/
void interactionTower(Tower *t, EnsEnemy *enemys);

/**
* @brief Met à jour les tours
* @param towers Pointeur sur EnsTower
* @param enemys Pointeur sur EnsEnemy
*/
void updateTowers(EnsTower *towers, EnsEnemy *enemys);

/**
* @brief Libère le tableaux des tours
* @param towers Pointeur sur EnsTower
*/
void freeTowers(EnsTower *towers);

/**
* @brief Retourne le nombres de tours
* @param towers Pointeur sur EnsTower
* @return Retourne le nombres de tours
*/
int getEnsTowerNb(const EnsTower *towers);
/**
* @brief Modifie le nombres de tours
* @param towers Pointeur sur EnsTower
* @param nb entier indiquant le nombre de tours
*/
void setEnsTowerNb(EnsTower *towers,int nb);
#endif
