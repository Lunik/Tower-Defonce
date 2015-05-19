#ifndef ENEMY_H
#define ENEMY_H

#include <stdio.h>
#include <stdlib.h>
#include "coordonates.h"



struct sEnemy 
{
	int id; 
	unsigned char type; //genre d'ennemi
	int flying;
	int hp; // point de vie
	int maxHp;
	int dmg;

	Coord position;
	int whereAmI;
	Coord *path[255];
	int pathCount;
	int loot;
	int slowcoeff;
	int slowtimer;
	int movetimer;
	int baseMoveTimer;
	int invincible;
};
typedef struct sEnemy Enemy;

/**
* @brief Crée un nouvel ennemi du type voulu avec l'id voulue
* @param char le type du nouvel ennemi
* @param id son id
* @return Retourne un pointeur sur Enemy
*/
Enemy* newEnemy(unsigned char type,int num);

/**
* @brief Modifie l'ennemi en ennemi de type volant
* @param e l'ennemi à modifier
*/
void setEnemyFly(Enemy *e);

/**
* @brief Transforme un ennemi en l'ennemi classique
* @param e l'ennemi à modifier
*/
void setEnemyClassic(Enemy *e);

/**
* @brief Transforme l'ennemi en ennemi de type boss
* @param e l'ennemi à modifier
*/
void setEnemyBoss(Enemy *e);

/**
* @brief Met à jour la position de l'ennemi et sa vie
* @param e l'ennemi à mettre à jour
*/
void updateEnemy(Enemy* e);

/**
* @brief Déplace l'ennemi
* @param e Pointeur sur Enemy
*/
void moveEnemy(Enemy *e);

/**
* @brief Modifie les points de vie de l'ennemi en lui infligeant des dégats
* @param e l'ennemi perdant de la vie
* @param dmg les dégats qu'il s'est pris
*/
void takeEnemyDamage(Enemy* e, int dmg);

/**
* @brief Détruit l'ennemi et libère sa mémoire
* @param e l'ennemi à détruire
*/
void killEnemy(Enemy* e);

/**
* @brief Evolue un ennemies, augmentation des pdv + loots
* @param e l'ennemi à evoluer
* @param wave numero de la vague
*/
void evolveEnemy(Enemy *e, int wave);

/**
* @brief Renvoie l'identifiant de l'ennemi
* @param e l'ennemi à modifier
* @return Retourne l'identifiant de l'ennemi
*/
int getEnemyId(const Enemy *e);
/**
* @brief Modifie l'identifiant de l'ennemi
* @param e Pointeur sur Enemy
* @param ID l'identifiant de l'ennemi
*/
void setEnemyId (Enemy *e, int ID);

/**
* @brief Renvoie le type de l'ennemi
* @param e l'ennemi nous intéressant
* @return Retourne le type de l'ennemi
*/
unsigned char getEnemyType (const Enemy* e);
/**
* @brief Modifie le type de l'ennemi
* @param e Pointeur sur Enemy
* @param c caractère indiquant le type de l'ennemi
*/
void setEnemyType (Enemy* e,unsigned char c);

/**
* @brief Renvoie si l'ennemi est volant
* @param e l'ennemi nous intéressant
* @return Retourne si l'ennemi est volant
*/
int getEnemyFlying (const Enemy* e);
/**
* @brief Transforme l'ennemi en ennemi volant
* @param e l'ennemi à modifier
* @param fly entier indiquant si l'ennemi devient volant
*/
void setEnemyFlying (Enemy* e,int fly);

/**
* @brief Renvoie les points de vie de l'ennemi
* @param e l'ennemi nous intéressant
* @return Retourne les points de vie de l'ennemi
*/
int getEnemyHP(const Enemy* e);

/**
* @brief Modifie les points de vie de l'enenemi
* @param e l'ennemi à modifier,
* @param hp les nouveaux points de vie de l'ennemi
*/
void setEnemyHP(Enemy* e, int hp);

/**
* @brief Renvoie les points de vie maximum de l'ennemi
* @param e l'ennemi nous intéressant
* @return Retourne les points de vie maximum de l'ennemi
*/
int getEnemyMaxHp (const Enemy* e);
/**
* @brief Modifie les points de vie maximum de l'ennemi
* @param e l'ennemi nous intéressant
* @param hp entier indiquant les points de vie maximum de l'ennemi
*/
void setEnemyMaxHp (Enemy* e, int hp);

/**
* @brief Renvoie les dommages que peut effectuer l'ennemi
* @param e l'ennemi nous intéressant
* @return Retourne les dommages que peut effectuer l'ennemi
*/
int getEnemyDmg (const Enemy* e);
/**
* @brief Modifie les dommages que peut effectuer l'ennemi
* @param e l'ennemi nous intéressant
* @param dmg entier indiquant les dommages que peut effectuer l'ennemi
*/
void setEnemyDmg (Enemy *e, int dmg);

/** 
* @brief Fournit la position actuelle de l'ennemi
* @param e l'ennemi dont on récupère la position
* @return Retourne la position actuelle de l'ennemi
*/
Coord getEnemyPosition (const Enemy* e);
/**
* @brief Modifie les coordonnées de l'ennemi
* @param e l'ennemi à modifier
* @param x position 
* @param y int
*/
void setEnemyPosition(Enemy* e, int x, int y);

/**
* @brief Renvoie la position de  l'ennemi dans le chemin
* @param e l'ennemi nous intéressant
* @return Retourne la position l'ennemi dans le chemin
*/
int getEnemyWhereAmI(const Enemy *e);
/**
* @brief Modifie la position de l'ennemi dans le chemin
* @param e l'ennemi nous intéressant
* @param wmi entier indiquant la position de l'ennemi dans le chemin
*/
void setEnemyWhereAmI(Enemy *e, int wmi);

/**
* @brief Renvoie le nombre de position parcourue par l'ennemi dans le chemin
* @param e l'ennemi nous intéressant
* @return Retourne le nombre de position parcourue par l'ennemi dans le chemin
*/
int getEnemyPathCount(const Enemy *e);
/**
* @brief Modifie le nombre de position parcourue par l'ennemi dans le chemin
* @param e l'ennemi nous intéressant
* @param pathcount entier indiquant le nombre de position parcourue par l'ennemi dans le chemin
*/
void setEnemyPathCount(Enemy *e,int pathcount);

/**
* @brief Renvoie l'argent gagné après avoir tué l'ennemi
* @param e l'ennemi nous intéressant
* @return Retourne l'argent gagné après avoir tué l'ennemi
*/
int getEnemyLoot (const Enemy* e);
/**
* @brief Modifie l'argent gagné après avoir tué l'ennemi
* @param e l'ennemi nous intéressant
* @param loot entier indiquant l'argent gagné après avoir tué l'ennemi
*/
void setEnemyLoot (Enemy* e, int loot);

/**
* @brief Renvoie le coefficient de ralentissement de la vitesse de l'ennemi
* @param e l'ennemi nous intéressant
* @return Retourne le coefficient de ralentissement de la vitesse de l'ennemi
*/
int getEnemySlowCoeff(const Enemy *e);
/**
* @brief Renvoie le temps de ralentissement de la vitesse de l'ennemi
* @param e l'ennemi nous intéressant
* @return Retourne le temps de ralentissement de la vitesse de l'ennemi
*/
int getEnemySlowTimer(const Enemy *e);
/**
* @brief Change la vitesse de l'ennemi et lance le timer du temps ralenti
* @param e ennemi à ralentir
* @param timer le coefficient de ralentissement
* @pram length la durée
*/
void slowEnemy(Enemy* e, int coeff, int timer);

/**
* @brief Renvoie la vitesse actuelle de l'ennemi
* @param e l'ennemi nous intéressant
* @return Retourne la vitesse actuelle de l'ennemi
*/
int getEnemyMoveTimer (const Enemy* e);
/**
* @brief Modifie la vitesse actuelle de l'ennemi
* @param e l'ennemi nous intéressant
* @param timer entier indiquant la vitesse actuelle de l'ennemi
*/
void setEnemyMoveTimer(Enemy *e, int timer);

/**
* @brief Renvoie la vitesse initiale de l'ennemi
* @param e l'ennemi nous intéressant
* @return Retourne la vitesse initiale de l'ennemi
*/
int getEnemyBaseMoveTimer (const Enemy* e);
/**
* @brief Modifie la vitesse de base de l'ennemi
* @param e l'ennemi nous intéressant
* @param timer entier indiquant la vitesse de base de l'ennemi
*/
void setEnemyBaseMoveTimer (Enemy* e, int timer);

/**
* @brief Renvoie si l'ennemi est invinvible
* @param e l'ennemi nous intéressant
* @return Retourne si l'ennemi est invinvible
*/
int getEnemyInvincible (const Enemy* e);

/**
* @brief Modifie si l'ennemi est invinvible
* @param e l'ennemi nous intéressant
*/
void setEnemyInvincible (Enemy* e, int YesOrNo);
#endif
