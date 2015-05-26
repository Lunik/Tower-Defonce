#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <stdio.h>
#include <stdlib.h>
#include "enemy.h"
#include "coordonates.h"
#include <math.h>


struct sProjectile{
	Enemy* target;
	Coord position;
	Coord direction;
	Coord origin;
	unsigned char spriteOrientation;
		
};typedef struct  sProjectile Projectile;

/**
 @brief Modifie l'attribut origin d'un projectile
 @param p Pointeur sur Projectile Le projectile à modifier
 @param orig cont Pointeur sur Coord Sa nouvelle origine
 */
void setProjectileOrigin(Projectile* p,const Coord* orig);


/**
 @brief Nous donne un pointeur sur l'attribut origine d'un projectile
 @param p const Pointeur sur Projectile Le projectile sur lequel on travaille
 @return Pointeur sur l'attribut origine de p
 */
Coord getProjectileOrigin(const Projectile* p);

 /**
 @brief Modifie l'attribut direction d'un projectile poru lui faire pointer vers sa target
 @param p Pointeur sur Projectile Le projectile dont la direction est à modifier
 */
void directionTotarget(Projectile* p);


/**
 @brief Crée un nouveau projectile alloué dynamiquement
 @param orig Coord L'origine du projectile (la position de la tour qui le lance)
 @param type char Le type de la tour (donc du projectile)
 @return Un pointeur sur le nouveau projectile dynamiquement alloué
 */
Projectile*  newProjectile(Coord orig, char type);


/**
 @brief Fait les modifications sur un projectile qauand sa tour change de cible
 @param p Pointeur sur Projectile Le projectile à changer
 @param e Pointeur sur Enemy La nouvelle cible
 @param orig Pointeur sur Coord Coordonnées d'origine du projectile (celles de sa tour).
  */
void changeTarget(Projectile* p,Enemy*e, Coord* orig);

/**
 @brief Applique les changements de position au projjectile p (fonction appelée à chaque incrémentation de temps)
 @param p Pointeur sur Projectile Le projectile à modifier
*/
void updateProjectile(Projectile* p);

/**
 @brief Libère l'espace mémoire pris par un projectile
 @param p Projectile le projectileà libérer
 */
void killProjectile(Projectile* p);

/**
 @brief Modifie la position d'un projectile 
 @param p Projectile Le projectile à modifier
 @param new Coord La nouvlele position
 */
void setProjectilePosition(Projectile* p,const  Coord* newp);


/**
 @brief Nous renvoie un pointeur sur les coordonnées de position d'un projectile
 @param p Pointeur sur Projectile Le projectile dont on veut la position
 @return Un pointeur sur l'attribut position 
 */
Coord* getProjectilePosition (Projectile *p);


/**
 @brief Modifie la position d'un projectile  en passant son abscise et son ordonnée en paramètre
 @param p Pointeur sur Projectile le projectile à modifier
 @param x double Sa nouvelle abscisse
 @param y double Sa nouvelle ordonnée
 */
void setProjectileCoordonates(Projectile* p,double x, double y);

/**
@brief Renvoi le sens du projectile g, d, h, b
@param p Pointeur sur Projectile
@return char Sens du projectile
*/
char getProjectileSens(Projectile *p);



#endif
