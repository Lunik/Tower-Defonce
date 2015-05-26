#include "projectile.h"
#include <stdio.h>
#include <stdlib.h>

 
 
 void directionTotarget(Projectile* p)
 {
	 p->direction.x = p->target->position.x - p->position.x;
	 p->direction.y = p->target->position.y - p->position.y;
	 
	 if(fabs(p->direction.y) >= fabs(p->direction.x))
	 {
		 if (p->direction.y > 0)
		 {p->spriteOrientation = 'b';}
		 else 
		 {p->spriteOrientation = 'h';}
	 }
	 else 
	 {
		 if (p->direction.x > 0)
		 { p->spriteOrientation= 'd';}
		 else
		 {p->spriteOrientation = 'g';}
		 }
	 normaliseCoord(&(p->direction));

}


void setProjectileTarget(Projectile* p, Enemy* e)
{
	p->target =  e;
}


void changeTarget(Projectile* p,Enemy* e, Coord* orig)
{
	setProjectilePosition(p, orig);
	setProjectileTarget(p, e);
}



Projectile*  newProjectile(Coord orig, char type)
{
	
    Projectile *p;
    p = malloc(sizeof(Projectile));
    setCoordonates(&(p->position), orig.x, orig.y);
    p->target = NULL;
    p->origin = orig;
    

 
    return p;
}


void updateProjectile(Projectile* p)
{
	
	
	if ( (p->target== NULL) || (getCoordsDistance(p->position, p->target->position) < 0.2) || p->target->hp <=0 )
	{	

		
		
		changeTarget(p,NULL,&(p->origin));
	}
	else{
		Coord move;
		directionTotarget(p);
		move = multipliedCoord(&(p->direction), 0.3);
		addCoords(&(p->position), &move);
	}

}
	
void setProjectilePosition(Projectile* p,const  Coord* newp)
{
	setCoordonates(&(p->position), newp->x, newp->y);
}

void setProjectileCoordonates(Projectile* p,double x, double y)
{
	setCoordonates(&(p->position), x, y);
}

Coord* getProjectilePosition ( Projectile *p)
{
	return &(p->position);
}

	
	
void setProjectileOrigin(Projectile* p,const Coord* orig)
{
	setCoordonates(&(p->origin), orig->x, orig->y);
	
}

Coord getProjectileOrigin(const Projectile* p)
{
	return p->origin;
}

void killProjectile(Projectile* p )
{
	free(p);
	p=NULL;
}



