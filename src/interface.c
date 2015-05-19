#include <stdio.h>
#include <stdlib.h>

#include "interface.h"

Cursor *newCursor(){
	Cursor *c;
	c = malloc(sizeof(Cursor));

	c->position.x = 0;	//setCursorPosition(c, newCoord(0, 0));
	c->position.y = 0;	//

	c->min.x = 0;
	c->min.y = 0;

	return c;
}

void moveCursorLeft(Cursor *c){
	if (c->position.x > c->min.x) 
	{
		c->position.x--;
	}
}
void moveCursorRight(Cursor *c)
{
	if (c->position.x < c->max.x) 
	{
		c->position.x++;
	}
}
void moveCursorUp(Cursor *c){
	if (c->position.y > c->min.y)
	{
		c->position.y--;
	}
}
void moveCursorDown(Cursor *c){
	if (c->position.y < c->max.y) 
	{
		c->position.y++;
	}
}

Interface* newInterface()
{
	Interface *i;
	i = malloc(sizeof(Interface));

	setInterfaceCursor(i,newCursor());

	return i;
}

void setInterfaceTower(Interface *i,Tower *t)
{
	i->tower = t;
}
Tower *getInterfaceTower(const Interface *i)
{
	return i->tower;
}

int buyInterfaceTower(unsigned char type, Coord *c, Map *map)
{
	int x,y;
	x = c->x;
	y = c->y;
	if(isCellBuildable(getCellFromXY(map, x, y)))
	{
		if(buyTower(&(map->towers), type, x, y,&(map->gold)))
		{
			map->grid[y][x]->build = 0;
			map->grid[x][y]->entity = map->towers->tab[map->towers->nb-1];
			return 1;
		}
	}
	return 0;
}

int sellInterfaceTower(Map *map, Coord *c, Tower *t){
	int x,y;
	x = c->x;
	y = c->y;
	if(t)
	{
		map->grid[x][y]->entity = NULL;
		map->grid[y][x]->build = 1;
		setMapGold(map,getMapGold(map) + (getTowerCost(t) / 2));
		sellTower(map->towers, t);
		return 1;
	}
	return 0;
}

int isCursorOnTower(Cursor *c, Map *map)
{
	int x,y;
	x = c->position.x;
	y = c->position.y;

	if(getCellEntity(map->grid[x][y]) != NULL)
	{
		return 1;
	}
	return 0;
}

Tower *getTowerUnderCursor(Cursor *c, Map *map)
{
	int x,y;
	x = c->position.x;
	y = c->position.y;
	return map->grid[x][y]->entity;
}

void updateInterface(Interface *i, Map *map)
{
	if(isCursorOnTower(getInterfaceCursor(i), map))
	{
		setInterfaceTower(i, getTowerUnderCursor(i->cursor, map));
	} else 
	{
		setInterfaceTower(i, NULL);
	}
}

void freeInterface(Interface *i)
{
	free( getInterfaceCursor(i) );
	free(i);
}

void setInterfaceCursor(Interface *i,Cursor *c)
{
	i->cursor = c;
}
Cursor *getInterfaceCursor(Interface *i)
{
	return i->cursor;
}

void setCursorPosition(Cursor *c, Coord coord)
{
	c->position = coord;
}
Coord getCursorPosition(const Cursor *c)
{
	return c->position;
}
