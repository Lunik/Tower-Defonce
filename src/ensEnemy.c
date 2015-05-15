#include <stdio.h>
#include <stdlib.h>

#include "ensEnemy.h"
#include "enemy.h"

EnsEnemy* newEnsEnemy()
{
	EnsEnemy *enemys;
	enemys = malloc(sizeof(EnsEnemy));
	setEnsEnemyNb(enemys, 0);
	return enemys;
}

void addEnsEnemy(EnsEnemy *enemys,Enemy *e)
{
	enemys->tab[enemys->nb] = e;
	setEnsEnemyNb(enemys, getEnsEnemyNb(enemys)+1);
}

void removeEnsEnemy(EnsEnemy *enemys,Enemy *e)
{
	int i,j;
	i=0;
	while (e != enemys->tab[i] && i < getEnsEnemyNb(enemys))
	{
		i++;
	}
	if (enemys->tab[i] == e)
	{
		for (j=i; j<enemys->nb-1; j++)
		{
			enemys->tab[j] = enemys->tab[j+1];
		}
		setEnsEnemyNb(enemys, getEnsEnemyNb(enemys)-1);
		killEnemy(e);
	}

}

void newEnsEnemyWave(EnsEnemy **enemys,int wave)
{
	int i,r;
	Enemy *e;
	int nb_enemy = (wave/2)*5 +1;
	freeEnemys(*enemys);
	*enemys = newEnsEnemy();
	if (!(wave%10)) //Si n° vague multiple de 10
	{ 
		//Boss vague
		e = newEnemy('B', 0);
		evolveEnemy(e,wave);
		addEnsEnemy(*enemys, e);
	} 
	else {
		//vague normale
		for (i=0; i<nb_enemy; i++) 
		{
			r = rand()%(10-0)+0;
			if (r<=7) { //0->7
				e = newEnemy('C', i);
			} 
			else 
			{
				e = newEnemy('F', i);
			}

			evolveEnemy(e, wave);

			setEnemyMoveTimer(e,getEnemyBaseMoveTimer(e)+(i*5));
			addEnsEnemy(*enemys, e);
		}
	}
}

Enemy* getEnemyfromID(EnsEnemy* enemys, int ID)
{
	int i;
	for(i=0; i < getEnsEnemyNb(enemys) ; i++)
	{ 
		if(enemys->tab[i]->id == ID)
			return enemys->tab[i];	
	}

	return NULL ;
}

void updateEnemys(EnsEnemy* enemys,int *gold){
	int i;
	for (i=0; i<getEnsEnemyNb(enemys); i++) 
	{
		if(enemys->tab[i]->hp > 0)
			updateEnemy(enemys->tab[i]);
		else 
		{
			*gold = *gold + enemys->tab[i]->loot;
			removeEnsEnemy(enemys, enemys->tab[i]);
		}
	}
}

void freeEnemys(EnsEnemy* e)                    
{ 
	int i;
	for (i = 0; i < getEnsEnemyNb(e); i++)
	{
		killEnemy(e->tab[i]);
	}

}

int getEnsEnemyNb(const EnsEnemy *enemys)
{
	return enemys->nb;
}
void setEnsEnemyNb(EnsEnemy *enemys, int nb)
{
	enemys->nb = nb;
}
