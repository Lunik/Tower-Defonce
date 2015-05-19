#include <stdio.h>
#include <stdlib.h>

#include "enemy.h"

Enemy* newEnemy(unsigned char type,int num)
{
	Enemy *e;
	e = malloc(sizeof(Enemy));
	setEnemyId(e,num);
	setEnemyWhereAmI(e,0);
	slowEnemy(e,0,0);
	setEnemyInvincible(e,0);

	initCoord(&(e->position));	//initCoord(& getEnemyPosition (e));
	switch (type) {
	case 'C':
		setEnemyClassic(e);
		break;
	case 'F':
		setEnemyFly(e);
		break;
	case 'B':
		setEnemyBoss(e);
		break;
	}
	return e;
}

void setEnemyFly (Enemy *e)
{
	setEnemyType(e,'F');
	setEnemyHP(e,100);
	setEnemyMaxHp(e,getEnemyHP(e));
	setEnemyFlying(e,1);
	setEnemyLoot(e,15);
	setEnemyBaseMoveTimer(e,15);
	setEnemyDmg(e,1);
}

void setEnemyClassic (Enemy *e)
{
	setEnemyType(e,'C');
	setEnemyHP(e,250);
	setEnemyMaxHp(e,getEnemyHP(e));
	setEnemyFlying(e,0);
	setEnemyLoot(e,20);
	setEnemyBaseMoveTimer(e,20);
	setEnemyDmg(e,1);
}

void setEnemyBoss (Enemy *e)
{
	setEnemyType(e,'B');
	setEnemyHP(e,5000);
	setEnemyMaxHp(e,getEnemyHP(e));
	setEnemyFlying(e,0);
	setEnemyLoot(e,1000);
	setEnemyBaseMoveTimer(e,50);
	setEnemyDmg(e,10);
}

void updateEnemy (Enemy* e)
{
	setEnemyMoveTimer(e,getEnemyMoveTimer(e)-1);

	if(getEnemySlowTimer(e)>0)
		slowEnemy(e,getEnemySlowCoeff(e),getEnemySlowTimer(e)-1);

	if(getEnemySlowTimer(e)==0){
		slowEnemy(e,0,0);
	}

	if(getEnemyMoveTimer(e) <0){
		if(getEnemyWhereAmI(e) < getEnemyPathCount(e)){
			moveEnemy(e);
			setEnemyMoveTimer(e,getEnemyBaseMoveTimer(e)+getEnemySlowCoeff(e));
		} else {
			setEnemyWhereAmI(e,getEnemyWhereAmI(e)+1);
		}
	}


}

void moveEnemy (Enemy* e)
{
	Coord nextCase = *e->path[e->whereAmI];	//Coord nextCase = *e->path[getEnemyWhereAmI(e)];
	setEnemyPosition(e, nextCase.y, nextCase.x);
	setEnemyWhereAmI(e,getEnemyWhereAmI(e)+1);
}

void takeEnemyDamage (Enemy* e, int dmg)
{
	int newHP = getEnemyHP(e) - dmg;
	setEnemyHP(e, newHP);
}

void killEnemy (Enemy* e)
{
	free(e);
	e = NULL;
}

void evolveEnemy (Enemy *e, int wave)
{

	if (getEnemyType(e) == 'B')
	{
		setEnemyHP(e,getEnemyHP(e)+getEnemyHP(e)*wave*wave);
		setEnemyMaxHp(e,getEnemyHP(e));
		setEnemyLoot(e,getEnemyLoot(e)+getEnemyLoot(e)*wave);
		setEnemyDmg(e,getEnemyDmg(e)+getEnemyDmg(e)*wave);
	}
	else
	{
		setEnemyHP(e,getEnemyHP(e)+getEnemyHP(e)*(wave/5));
		setEnemyMaxHp(e,getEnemyHP(e));
		setEnemyLoot(e,getEnemyLoot(e)+getEnemyLoot(e)*(wave/5));
		setEnemyDmg(e,getEnemyDmg(e)+getEnemyDmg(e)*wave);
	}
}

int getEnemyId(const Enemy *e)
{
	return e->id;
}

void setEnemyId (Enemy *e, int ID)
{
	e->id = ID;
}

unsigned char getEnemyType (const Enemy* e)
{
	return e->type;
}

void setEnemyType (Enemy* e,unsigned char c)
{
	e->type = c;
}

int getEnemyFlying (const Enemy* e)
{
	return e->flying;
}

void setEnemyFlying (Enemy* e,int fly)
{
	e->flying = fly;
}

int getEnemyHP (const Enemy* e)
{
	return e->hp;
}

void setEnemyHP (Enemy* e, int hp)
{
	e->hp = hp;
}

int getEnemyMaxHp (const Enemy* e)
{
	return e->maxHp;
}

void setEnemyMaxHp (Enemy* e, int hp)
{
	e->maxHp = hp;
}

int getEnemyDmg (const Enemy* e)
{
	return e->dmg;
}

void setEnemyDmg (Enemy *e, int dmg)
{
	e->dmg = dmg;
}

Coord getEnemyPosition (const Enemy* e)
{
	return e->position;
}

void setEnemyPosition (Enemy* e, int x, int y)
{
	e->position.x = x;
	e->position.y = y;
}

int getEnemyWhereAmI(const Enemy *e)
{
	return e->whereAmI;
}

void setEnemyWhereAmI(Enemy *e, int wmi)
{
	e->whereAmI = wmi;
}

int getEnemyPathCount(const Enemy *e)
{
	return e->pathCount;
}

void setEnemyPathCount(Enemy *e,int pathcount)
{
	e->pathCount = pathcount;
}

int getEnemyLoot (const Enemy* e)
{
	return e->loot;
}

void setEnemyLoot (Enemy* e,int loot)
{
	e->loot = loot;
}

int getEnemySlowCoeff(const Enemy *e)
{
	return e->slowcoeff;
}

int getEnemySlowTimer(const Enemy *e)
{
	return e->slowtimer;
}

void slowEnemy (Enemy* e, int coeff, int length)
{
	e->slowcoeff = coeff;
	e->slowtimer = length;
}

int getEnemyMoveTimer (const Enemy* e)
{
	return e->movetimer;
}

void setEnemyMoveTimer(Enemy *e, int timer)
{
	e->movetimer = timer;
}

int getEnemyBaseMoveTimer (const Enemy* e)
{
	return e->baseMoveTimer;
}

void setEnemyBaseMoveTimer (Enemy* e, int timer)
{
	e->baseMoveTimer = timer;
}

int getEnemyInvincible (const Enemy* e)
{
	return e->invincible;
}

void setEnemyInvincible (Enemy* e, int YesOrNo)
{
	e->invincible = YesOrNo;
}
