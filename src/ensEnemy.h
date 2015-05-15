#ifndef ENSENEMY_H
#define ENSENEMY_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "enemy.h"

struct sEnsEnemy{
	Enemy *tab[1024];
	int nb;
};
typedef struct sEnsEnemy EnsEnemy;


/**
* @brief Cree et allours l'espace pour un nouvel ensemble d'ennemis.
*/
EnsEnemy *newEnsEnemy();

/**
* @brief Rajoute un ennemi à l'ensemble des ennemis
* @param enemys Pointeur sur EnsEnemy
* @param e Pointeur sur Enemy indiquant l'ennemi qui nous intéresse
*/
void addEnsEnemy(EnsEnemy *enemys,Enemy *e);

/**
* @brief Enlève un ennemi de l'ensemble des ennemis (le libère au passage)
* @param enemys Pointeur sur EnsEnemy
* @param e Pointeur sur Enemy indiquant l'ennemi qui nous intéresse
*/
void removeEnsEnemy(EnsEnemy *enemys,Enemy *e);

/**
* @brief Créé une nouvelle vague d'ennemi
* @param enemys Pointeur sur EnsEnemy
* @param nb entier indiquant le nombre ennemi
*/
void newEnsEnemyWave(EnsEnemy **enemys,int nb);

/**
* @brief Récupère un identifiant et renvoie l'ennemi de l'ensemble des ennemis y correspondant
* @param enemys Pointeur sur EnsEnemy
* @param ID entier indiquant l'identifiant de l'ennemi qui nous intéresse
* @return Retourne l'ennemi de l'ensemble des ennemis y correspondant à l'identifiant
*/
Enemy* getEnemyfromID(EnsEnemy* enemys, int ID);

/**
* @brief Met à jour les ennemies
* @param enemys Pointeur sur ensEnemy
* @param gold Pointeur indiquant la quantité de "gold" restant
*/
void updateEnemys(EnsEnemy* enemys,int *gold);

/**
* @brief Libère tout les ennemies de l'ensemble des ennemis
* @param e Pointeur sur ensEnemy
*/
void freeEnemys(EnsEnemy* e);

/**
* @brief Renvoie le nombre d'ennemi restant de l'ensemble des ennemis
* @param enemys Pointeur sur EnsEnemy
* @param nb entier indiquant le nombre ennemi
* @return Returne le nombre d'ennemi restant de l'ensemble des ennemis
*/
int getEnsEnemyNb(const EnsEnemy *enemys);
/**
* @brief Modifie le nombre d'ennemi restant de l'endemble des ennemis
* @param enemys Pointeur sur EnsEnemy
* @param nb entier indiquant le nombre ennemi
*/
void setEnsEnemyNb(EnsEnemy *enemys, int nb);
#endif
