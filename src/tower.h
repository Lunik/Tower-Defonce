#ifndef TOWER_H
#define TOWER_H

#include <stdlib.h>
#include <stdio.h>


#include <math.h>

#include "coordonates.h"
#include "projectile.h"

struct sTower{
    int id;
    
    int lvl;
    unsigned char type;
    int cost;
    
    double rangeMin;
    double rangeMax;
    double speedAtt;
    double dmg;
    
    Coord position;
    int idtarget; //id d'un enemy
    int attackTimer;
    int defaultAttackTimer;
    Projectile* shot;

};
typedef struct sTower Tower;
#endif

/**
 * @brief initilise la tower
 * @param type chaîne de caractère indiquant le type de la tower, id l'identifiant de la Tower
 */
Tower* newTower(unsigned char type,int id);

void setTowerKnight (Tower *t);

/**
 * @brief création tower Archer
 * @param *t Tower
 */
void setTowerArcher (Tower *t);

/**
 * @brief création tower Mage
 * @param *t Tower
 */
void setTowerMage (Tower *t);

/**
 * @brief création tower Canon
 * @param *t Tower
 */
void setTowerCannon(Tower *t);

/**
 * @brief fonction modifiant les caractéristiques
 * @param *t Tower
 */
void evolveTower (Tower *t, int *gold);

/**
 * @brief fonction modifiant la cible de la Tower
 * @param *t Tower, id l'identifiant de la cible de la Tower
 */
void attackTowerEnemy(Tower *t, const int id);

/**
 * @brief fonction vérifiant si une position est dans la range (retourne 1 si dans la range, 0 sinon)
 * @param *t Tower, x position en X de Enemy, y position en Y de Enemy
 */
int isEnemyinrange(Tower *t, const int x, const int y);

/**
 * @brief Met à jour la tour
 * @param t Pointeur sur Tower
 */
void updateTower(Tower *t);

/**
 * @brief Detruit la tour (free)
 * @param t Pointeur sur Tower
 */
void destroyTower(Tower *t);
 
 /**
 @brief Renvoie l'identifiant de la tour
 @param t Pointeur sur Tower
 @return Retourne l'identifiant de la tour
 */
int getTowerId(const Tower *t);
/**
  @brief Modifie l'identifiant de la tour
  @param t Pointeur sur Tower
  @param id entier indiquant l'identifiant de la tour
 */
void setTowerId(Tower *t, int id);
 
/**
 @brief Renvoie le niveau de la tour
 @param t Pointeur sur Tower
 @return Retourne le niveau de la tour
 */
int getTowerLvl(const Tower *t);
/**
  @brief Modifie le niveau de la tour
  @param t Pointeur sur Tower
  @param lvl entier indiquant le niveau de la tour
 */
void setTowerLvl(Tower *t,int lvl);

/**
 @brief Renvoie le type de la tour
 @param t Pointeur sur Tower
 @return Retourne le type de la tour
 */
unsigned char getTowerType(const Tower *t);
/**
  @brief Modifie le type de la tour
  @param t Pointeur sur Tower
  @param c caractère indiquant le type de la tour
 */
void setTowerType(Tower *t,unsigned char c);

/**
 @brief Renvoie le prix de la tour
 @param t Pointeur sur Tower
 @return Retourne prix de la tour
 */
int getTowerCost(const Tower *t);
/**
  @brief Modifie le prix de la tour
  @param t Pointeur sur Tower
  @param cost entier indiquant le prix de la tour
 */
void setTowerCost(Tower *t,int cost);

/**
 @brief Renvoie la portée maximale de la tour
 @param t Pointeur sur Tower
 @return Retourne la portée maximale de la tour
 */
double getTowerRangeMax(const Tower *t);
/**
 @brief Renvoie la portée de la tour
 @param t Pointeur sur Tower
 @return Retourne la portée minimale de la tour
 */
double getTowerRangeMin(const Tower *t);
/**
  @brief Modifie la portée de la tour
  @param t Pointeur sur Tower
  @param rMax entier indiquant la portée maximale de la tour
  @param rMin entier indiquant la portée minimale de la tour
 */
void setTowerRange(Tower *t,double rMin, double rMax);

/**
 @brief Renvoie les dommages de la tour
 @param t Pointeur sur Tower
 @return Retourne les dommages de la tour
 */
double getTowerDmg(const Tower *t);
/**
  @brief Modifie les dommages de la tour
  @param t Pointeur sur Tower
  @param dmg entier indiquant les dommages de la tour
 */
void setTowerDmg(Tower *t,int dmg);

/**
 @brief Renvoie la position en X et Y de la tour
 @param t Pointeur sur Tower
 @return Retourne la position en X et Y de la tour
 */
Coord *getTowerPosition(Tower *t);

/**
 @brief Modifie la position la tour
 @param t Pointeur sur Tower
 @param x position en X de Tower
 @param y position en Y de Tower
 */
void setTowerPosition (Tower *t, const int x, const int y);

/**
 @brief Renvoie la cible de la tour
 @param t Pointeur sur Tower
 @return Retourne la cible de la tour
 */
int getTowerTarget(const Tower *t);
/**
 @brief Modifie la cible la tour
 @param t Pointeur sur Tower
 @param target entier indiquant la cible de la tour
 */
void setTowerTarget(Tower *t,int target);

/**
 @brief Renvoie le temps avant la prochaine attaque de la tour
 @param t Pointeur sur Tower
 @return Retourne la cible de la tour
 */
int getTowerTimer(const Tower *t);
/**
 @brief Modifie le temps avant la prochaine attaque la tour
 @param t Pointeur sur Tower
 @param timer entier indiquant le temps avant la prochaine attaque de la tour
 */
void setTowerTimer(Tower *t,int timer);

/**
 @brief Renvoie le temps par défaut avant la prochaine attaque de la tour
 @param t Pointeur sur Tower
 @return Retourne le temps par défaut avant la prochaine attaque de la tour
 */
int getTowerDefaultTimer(const Tower *t);
/**
 @brief Modifie le temps par défaut avant la prochaine attaque la tour
 @param t Pointeur sur Tower
 @param timer entier indiquant le temps par défaut avant la prochaine attaque de la tour
 */
void setTowerDefaultTimer(Tower *t,int timer);

/**
 @brief Met à jour le projectile
 @param t Pointeur sur Tower
 @param p Pointeur sur Projectile
 */
void setTowerProjectile(Tower *t,Projectile *p);

/**
 @brief Renvoie les informations du projectile de la tour
 @param t Pointeur sur Tower
 @return Retourne un Pointeur sur Projectile
 */
Projectile *getTowerProjectile(const Tower *t);
