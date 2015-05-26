#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "tower.h"

Tower* newTower(unsigned char type,int id)
{
    Tower *t;
    t = malloc(sizeof(Tower));
    setTowerId(t, id);
    setTowerPosition (t, -1, -1);
    setTowerTimer(t,0);
    setTowerProjectile(t,newProjectile(t->position, t->type));
    
    switch (type) {
        case 'K':
            setTowerKnight(t);
            break;
        case 'A':
            setTowerArcher(t);
            break;
        case 'M':
            setTowerMage(t);
            break;
        case 'C':
            setTowerCannon(t);
            break;
    }
    return t;
}

void setTowerKnight (Tower *t)
{
	setTowerId(t, -1);
	
    setTowerLvl(t,1);
    setTowerType(t,'K');
    
    setTowerCost(t,150);
    
    setTowerRange(t ,0 , 1.2);
    setTowerDefaultTimer(t,25);
    setTowerDmg(t,150);
}

void setTowerArcher (Tower *t)
{      
    setTowerId(t, -1);
	
    setTowerLvl(t,1);
    setTowerType(t,'A');
    
    setTowerCost(t,300);
    
    setTowerRange(t ,2 , 3.6);
    setTowerDefaultTimer(t,20);
    setTowerDmg(t,80);
}

void setTowerMage (Tower *t)
{ 
	setTowerId(t, -1);
	
    setTowerLvl(t,1);
    setTowerType(t,'M');
    
    setTowerCost(t,500);
    
    setTowerRange(t ,0 , 2.1);
    setTowerDefaultTimer(t,30);
    setTowerDmg(t,100);
}

void setTowerCannon(Tower *t)
{  
    setTowerId(t, -1);
	
    setTowerLvl(t,1);
    setTowerType(t,'C');
    
    setTowerCost(t,1000);
    setTowerRange(t ,1 , 2);
    setTowerDefaultTimer(t,80);
    setTowerDmg(t,500);
}

void setTowerPosition (Tower *t, const int x, const int y)
{
    t->position.x = x;
    t->position.y = y;
}

void evolveTower (Tower *t, int *gold)
{
    if (t->lvl < 5 && *gold >= t->cost)
    {
        *gold = *gold - getTowerCost(t);
        
        setTowerLvl(t ,getTowerLvl(t)+1 );
        setTowerCost(t ,getTowerCost(t)*(getTowerLvl(t)*getTowerLvl(t)) );
        
        if (getTowerType(t) == 'K')
        {
            setTowerDmg(t ,getTowerDmg(t)*1.5*getTowerLvl(t));
			setTowerDefaultTimer(t,getTowerDefaultTimer(t)*0.8);
            setTowerRange(t,getTowerRangeMin(t), getTowerRangeMax(t)*1.10);
        }
        else if (getTowerType(t) == 'A')
        {
            setTowerDmg(t ,getTowerDmg(t)*1.25*getTowerLvl(t));
			setTowerDefaultTimer(t,getTowerDefaultTimer(t)*0.9);
            setTowerRange(t,getTowerRangeMin(t), getTowerRangeMax(t)*1.30);
        }
        else if(getTowerType(t) == 'M')
        {
            setTowerDmg(t ,getTowerDmg(t)*1.15*getTowerLvl(t));
			setTowerDefaultTimer(t,getTowerDefaultTimer(t)*0.92);
            setTowerRange(t,getTowerRangeMin(t), getTowerRangeMax(t)*1.15);
        }
        else if(getTowerType(t) == 'C')
        {
            setTowerDmg(t ,getTowerDmg(t)*1.0*getTowerLvl(t));
			setTowerDefaultTimer(t,getTowerDefaultTimer(t)*0.95);
            setTowerRange(t,getTowerRangeMin(t), getTowerRangeMax(t)*1.05);
        }     
    }
}

void attackTowerEnemy(Tower *t, const int id)
{
	setTowerTarget(t, id);
	setTowerTimer(t,getTowerDefaultTimer(t));
}

int isEnemyinrange(Tower *t, const int x, const int y)
{
	double distanceEnemy;
    Coord c;
    c.x=x;
    c.y=y;
    distanceEnemy = getCoordsDistance(t->position, c);
    
	if ( (distanceEnemy >= getTowerRangeMin(t)) && (distanceEnemy <= getTowerRangeMax(t)) )
	{
		
		return 1;
	}
	return 0;
}

void updateTower(Tower *t)
{
    if(getTowerTimer(t) >0)
    {
        setTowerTimer(t,getTowerTimer(t)-1);
    }
    if (getTowerProjectile(t) != NULL &&  t->shot->target)
    {
		updateProjectile(t->shot);
    }

}

void destroyTower(Tower *t)
{
    killProjectile(t->shot);
    free(t);
    t = NULL;
}

int getTowerId(const Tower *t)
{
	return t->id;
}

void setTowerId(Tower *t, int id)
{
	t->id = id;
}

int getTowerLvl(const Tower *t)
{
	return t->lvl;
}
void setTowerLvl(Tower *t,int lvl)
{
	t->lvl = lvl;
}

unsigned char getTowerType(const Tower *t)
{
	return t->type;
}

void setTowerType(Tower *t,unsigned char c)
{
	t->type = c;
}

int getTowerCost(const Tower *t)
{
	return t->cost;
}

void setTowerCost(Tower *t,int cost)
{
	t->cost = cost;
}

double getTowerRangeMax(const Tower *t)
{
	return t->rangeMax;
}

double getTowerRangeMin(const Tower *t)
{
	return t->rangeMin;
}

void setTowerRange(Tower *t,double rMin, double rMax)
{
	t->rangeMin = rMin;
	t->rangeMax = rMax;
}

double getTowerDmg(const Tower *t)
{
	return t->dmg;
}

void setTowerDmg(Tower *t,int dmg)
{
	t->dmg = dmg;
}

Coord *getTowerPosition(Tower *t)
{
	return &(t->position);
}

int getTowerTarget(const Tower *t)
{
	return t->idtarget;
}

void setTowerTarget(Tower *t,int target)
{
	t->idtarget = target;
}

int getTowerTimer(const Tower *t)
{
	return t->attackTimer;
}

void setTowerTimer(Tower *t,int timer)
{
	t->attackTimer = timer;
}

int getTowerDefaultTimer(const Tower *t)
{
	return t->defaultAttackTimer;
}

void setTowerDefaultTimer(Tower *t,int timer)
{
	t->defaultAttackTimer = timer;
}

void setTowerProjectile(Tower *t,Projectile *p)
{
	t->shot = p;
}
Projectile* getTowerProjectile(const Tower *t)
{
    return t->shot;
}
