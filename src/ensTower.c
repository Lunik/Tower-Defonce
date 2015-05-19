#include <stdlib.h>
#include <stdio.h>

#include "ensTower.h"

EnsTower *newEnsTower()
{
	EnsTower *towers;
	towers = malloc(sizeof(EnsTower));

	setEnsTowerNb(towers,0);
	return towers;
}

void addEnsTower(EnsTower *towers,Tower *t)
{
	towers->tab[getEnsTowerNb(towers)] = t;
	setEnsTowerNb(towers,getEnsTowerNb(towers)+1);
}

void removeEnsTower(EnsTower *towers,Tower *t)
{
	int i,j;
	i=0;
	while ( (towers->tab[i] != t) && (i < getEnsTowerNb(towers)) )
	{
		i++;
	}
	if (towers->tab[i] == t)
	{
		for (j=i; j<towers->nb-1; j++)
		{
			towers->tab[j] = towers->tab[j+1];
		}
		setEnsTowerNb(towers,getEnsTowerNb(towers)-1);
		destroyTower(t);
	}
}

int buyTower(EnsTower **ensTower, unsigned char type, int posX, int posY, int *gold)
{
	Tower *t;
	t = NULL;
	if (type == 'K')
	{
		t = newTower('K',(*ensTower)->nb);
	}
	else if (type == 'A')
	{
		t = newTower('A',(*ensTower)->nb);
	}
	else if (type == 'M')
	{
		t = newTower('M',(*ensTower)->nb);
	}else if (type == 'C')
	{
		t = newTower('C',(*ensTower)->nb);
	}
	setTowerPosition(t, posX, posY);
	setProjectilePosition(getTowerProjectile(t), getTowerPosition(t));
	setProjectileOrigin(getTowerProjectile(t), getTowerPosition(t));

	if(*gold >= getTowerCost(t)){
		addEnsTower(*ensTower, t);
		*gold = *gold - getTowerCost(t);
		return 1;
	} else {
		destroyTower(t);
		return 0;
	}
}

void sellTower (EnsTower *towers, Tower *t)
{
	removeEnsTower(towers, t);
}

void interactionTower(Tower *t, EnsEnemy *enemys)
{
	int iE,i, dist;
	Enemy* e;

	for (iE=0; iE < getEnsEnemyNb(enemys); iE++)
	{
		//Si la tour peut attaquer
		if((isEnemyinrange(t, enemys->tab[iE]->position.x, enemys->tab[iE]->position.y)==1) && !getEnemyInvincible (enemys->tab[iE]) && t->attackTimer == 0 )
		{
			//if (t->attackTimer == 0)
			//{
				//Si c'est un mage ou un archer
				if ((t->type == 'M') || (t->type == 'A'))
				{
					attackTowerEnemy(t, getEnemyId(enemys->tab[iE]));
					e = getEnemyfromID(enemys, enemys->tab[iE]->id);
					changeTarget(getTowerProjectile(t), e, getTowerPosition(t));

					//Si c'est un mage
					if (t->type == 'M')
					{
						slowEnemy(e, 100, 1000);
						updateEnemy(enemys->tab[iE]);
					}
					takeEnemyDamage(e, getTowerDmg(t));
				}
				//Si c'est un canon ou un chevalier
				else if ((t->type == 'K') || (t->type == 'C'))
				{
					//Si l'enemie ne vole pas
					if (getEnemyFlying (enemys->tab[iE]) == 0)
					{
						//Si c'est un canon
						if (t->type == 'C')
						{
							//attaque en zone
							for (i=0;	i < getEnsEnemyNb(enemys); i++)
							{
								attackTowerEnemy(t, getEnemyId(enemys->tab[iE]));
								e = getEnemyfromID(enemys, getEnemyId(enemys->tab[iE]));
								changeTarget(getTowerProjectile(t), e, getTowerPosition(t));
								takeEnemyDamage(e, getTowerDmg(t));
										
								if (i != iE)
								{
									dist = getCoordsDistance(getEnemyPosition (enemys->tab[i]), getEnemyPosition (enemys->tab[iE]));
									if (dist <= 2 && dist > 0)
									{
										attackTowerEnemy(t, getEnemyId(enemys->tab[i]));
										e = getEnemyfromID(enemys, getEnemyId(enemys->tab[i]));
										changeTarget(getTowerProjectile(t), e, getTowerPosition(t));
										takeEnemyDamage(e, getTowerDmg(t));
									}
								}
							}
							//Si c'est un chevalier
						} else
						{
							attackTowerEnemy(t, getEnemyId(enemys->tab[iE]));
							e = getEnemyfromID(enemys, getEnemyId(enemys->tab[iE]));
							takeEnemyDamage(e, getTowerDmg(t));
						}
					}
			}
		} 
	}
}

void updateTowers(EnsTower *towers, EnsEnemy *enemys)
{
	int i;

	for(i=0;i<getEnsTowerNb(towers);i++){
		updateTower(towers->tab[i]);
		interactionTower (towers->tab[i], enemys);
	}
}

void freeTowers(EnsTower *towers)
{
	int i;
	for (i=0; i<getEnsTowerNb(towers); i++)
	{
		destroyTower(towers->tab[i]);
	}
}

int getEnsTowerNb(const EnsTower *towers)
{
	return towers->nb;
}
void setEnsTowerNb(EnsTower *towers,int nb)
{
	towers->nb = nb;
}
