#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <stdio.h>
#include <stdlib.h>
#include "enemy.h"
#include "coordonates.h"


struct sProjectile{
	Enemy* target;
	Coord position;
	Coord direction;
	Coord origin;
		
};typedef struct  sProjectile Projectile;

/**
 @brief Modifie l'attribut origin d'un projectile
 @param p le projectile à modifier, orig sa nouvelle origine
 */
void setProjectileOrigin(Projectile* p,const Coord* orig);


/**
 @brief Nous donne un pointeur sur l'attribut origine d'un projectile
 @param p le projectile sur lequel on travaille
 @return Pointeur sur l'attribut origin de p
 */
Coord getProjectileOrigin(const Projectile* p);

 /**
 @brief Modifie l'attribut direction d'un projectile poru lui faire pointer vers sa target
 @param p le projectile dont la direction est à modifier
 */
void directionTotarget(Projectile* p);


/**
 @brief Crée un nouveau projectile alloué dynamiquement
 @param orig l'origine du projectile (la position de la tour qui le lance), type le type de la tour (donc du projectile)
 @return un pointeur sur le nouveau projectile dynamiquement alloué
 */
Projectile*  newProjectile(Coord orig, char type);


/**
 @brief Fait les modifications sur un projectile qauand sa tour change de cible
 @param p le projectile à changer, e la nouvelle cible
  */
void changeTarget(Projectile* p,Enemy*e, Coord* orig);

/**
 @brief Applique les changements de position au projjectile p (fonction appelée à chaque incrémentation de temps)
 @param p le projectile à modifier
*/
void updateProjectile(Projectile* p);

/**
 @brief Libère l'espace mémoire pris par un projectile
 @param p le projectileà libérer
 */
void killProjectile(Projectile* p);

/**
 @brief Modifie la position d'un projectile 
 @param p le projectile à modifier, new une structure Coord qui sera la nouvlele position
 */
void setProjectilePosition(Projectile* p,const  Coord* newp);


/**
 @brief Nous renvoie un pointeur sur les coordonnées de position d'un projectile
 @param p le projectile dont on veut la position
 @return Un pointeur sur l'attribut position 
 */
Coord* getProjectilePosition (Projectile *p);


/**
 @brief Modifie la position d'un projectile  en passant son abscise et son ordonnée en paramètre
 @param p le projectile à modifier, x sa nouvelle abscisse, y sa nouvelle ordonnée
 */
void setProjectileCoordonates(Projectile* p,double x, double y);
#endif
