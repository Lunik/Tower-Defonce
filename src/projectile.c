#include "projectile.h"
#include <stdio.h>
#include <stdlib.h>

 
 
 void directionTotarget(Projectile* p)
 {
	 p->direction.x = p->target->position.x - p->position.x;
	 p->direction.y = p->target->position.y - p->position.y;
	 //printf("La direction : %f %f  \n", p->direction.x, p->direction.y);
	 normaliseCoord(&(p->direction));
	 //printf("%f %f\n", p->direction.x, p->direction.y);
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
    

   /* switch (type) {
        case 'A':
			p->speed= 1.0;
            break;
        case 'C':
			p->speed = 0.005;
            break;
        case 'M':
			p->speed = 0.005;
            break;																																																									//malbossux
    }*/																														
    
    return p;
}


void updateProjectile(Projectile* p)
{
	//printf("origine : %f %f", p->origin.x, p->origin.y); //testatuin
	
	if ( (p->target== NULL) || (getCoordsDistance(p->position, p->target->position) < 0.2) || p->target->hp <=0 )
	{	

		//printf("youplaboum \n");
		
		changeTarget(p,NULL,&(p->origin));
	}
	else{
		Coord move;
		directionTotarget(p);
		move = multipliedCoord(&(p->direction), 0.2);
		addCoords(&(p->position), &move);
    	//printf("L'ennemi: %f %f,Target %d, PV ennemi : %d\n",p->target->position.x,p->target->position.y, p->target,p->target->hp);
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

