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
	//double speed;
		
};typedef struct  sProjectile Projectile;


 
 
void directionTotarget(Projectile* p);

Projectile*  newProjectile(Coord orig, char type);

void changeTarget(Projectile* p,Enemy*e, Coord* orig);


void updateProjectile(Projectile* p);

void killProjectile(Projectile* p);

void setProjectilePosition(Projectile* p,const  Coord* new);

Coord getProjectilePosition (const Projectile *p);
void setProjectileCoordonates(Projectile* p,double x, double y);
#endif
