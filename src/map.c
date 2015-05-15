#include <stdio.h>
#include <stdlib.h>

#include "ensTower.h"
#include "ensEnemy.h"
#include "map.h"


Map *newMap(int dimX, int dimY)
{
	Map *m;
	m = malloc(sizeof(Map));
	setMapTowers(m, newEnsTower());
	setMapEnemys(m,newEnsEnemy());
	setMapDim(m,dimX, dimY);
	initMap(m);
	setMapWave(m,0);
	setMapLife(m,1000);
	setMapGold(m,1000);
	return m;
}

Cell *newMapCell(int build,int path)
{
	Cell *c;
	c = malloc(sizeof(Cell));
	setCellBuild(c,build);
	setCellPath(c,path);
	setCellEntity(c,NULL);
	return c;
}

void initMap(Map *map)
{
	int i,j,pathcount;
	setMapDim(map,15, 15);
	Coord dim = getMapDim(map);
	pathcount = 1;
	const char MAP_PATTERN[15][15] = {
		"#######=====###",
		"#######=###=###",
		"#######=###=###",
		"B=#=====###=###",
		"#=#=#######=###",
		"#=#==#####==###",
		"#=##=####==####",
		"#====####=#####",
		"#########=#####",
		"####======#####",
		"###==######===E",
		"##==####====###",
		"##=#####=######",
		"##==###==######",
		"###=====#######"
	};
	Coord *coord, *fin, *debut;
	Cell *c;
	fin = malloc(sizeof(Coord));

	for (j=0; j<dim.x; j++) {
		for (i=0; i<dim.y; i++) {
			coord = malloc(sizeof(Coord));
			c = malloc(sizeof(Cell));
			setCoordonates(coord, j, i);
			if (MAP_PATTERN[j][i] == '#') {
				c = newMapCell(1, 0);
				setCellBegin(c,0);
				setCellEnd(c,0);
			} else if (MAP_PATTERN[j][i] == '='){
				c = newMapCell(0, 1);
				setCellBegin(c,0);
				setCellEnd(c,0);
			} else if (MAP_PATTERN[j][i] == 'B'){
				c = newMapCell(0, 1);
				setCellBegin(c,1);
				setCellEnd(c,0);
				setMapStart(map, coord);
				debut = coord;
			} else if (MAP_PATTERN[j][i] == 'E'){
				c = newMapCell(0, 1);
				setCellBegin(c,0);
				setCellEnd(c,1);
				setMapEnd(map,coord);
				fin = coord;
			}
			setCellEntity(c,NULL);
			setCellPosition(c,coord);

			map->grid[j][i] = c;
		}
	}

	//Ecriture du chemin !
	int x,y;
	char lastDir = 'f';
	coord = debut;
	pathcount = 0;

	map->path[pathcount] = coord;
	pathcount++;

	while (!equalCoords(fin,coord)) {

		x = coord->x;
		y = coord->y;

		if (x+1 < dim.x && getCellPath(map->grid[x+1][y]) && lastDir != 'g') {
			coord = malloc(sizeof(Coord));
			setCoordonates(coord, x+1, y);
			lastDir = 'd';
		} else if (x-1 >= 0 && getCellPath(map->grid[x-1][y]) && lastDir != 'd'){
			coord = malloc(sizeof(Coord));
			setCoordonates(coord, x-1, y);
			lastDir = 'g';
		} else if (y+1 < dim.y && getCellPath(map->grid[x][y+1]) && lastDir != 'h'){
			coord = malloc(sizeof(Coord));
			setCoordonates(coord, x, y+1);
			lastDir = 'b';
		} else if (y-1 >= 0 && getCellPath(map->grid[x][y-1]) && lastDir != 'b'){
			coord = malloc(sizeof(Coord));
			setCoordonates(coord, x, y-1);
			lastDir = 'h';
		}

		map->path[pathcount] = coord;
		pathcount++;
	}
	map->path[pathcount] = fin;
	pathcount++;
	setMapPathCount(map,pathcount);

}

void setMapCell(Cell *grid[255][255], int x, int y, void *e)
{
	grid[x][y]->entity = e;
}

void updateMap(Map *map)
{
	int i;

	updateTowers(getMapTowers(map),getMapEnemys(map));
	updateEnemys(getMapEnemys(map), &(map->gold));

	//Si un ennemies arrive au bout du chemin
	for (i=0; i<getMapEnemys(map)->nb; i++) 
	{
		if(getMapEnemys(map)->tab[i]->whereAmI > getMapPathCount(map))
		{
			map->life = map->life - map->enemys->tab[i]->dmg;
			removeEnsEnemy(getMapEnemys(map), getMapEnemys(map)->tab[i]);
		}
	}

}

void afficheMap(Map *map)
{
	int i,j;
	Coord dim = getMapDim(map);
	for (j=0; j<dim.x; j++)
	{
		for (i=0; i<dim.y; i++)
		{
			if (getCellEntity(map->grid[j][i]) != NULL) 
			{
				printf("%c ",getCellEntity(map->grid[j][i])->type);
			} 
			else if (getCellPath(map->grid[j][i])) 
			{
				printf("= ");
			} 
			else if(getCellBuild(map->grid[j][i]))
			{
				printf(". ");
			}
		}
		printf("\n");
	}
}

void newWave(Map *map)
{
	int i;
	setMapWave(map, getMapWave(map)+1);
	newEnsEnemyWave(&(map->enemys), getMapWave(map));
	for (i=0; i<getMapEnemys(map)->nb; i++) 
	{
		setEnemyPosition(getMapEnemys(map)->tab[i], map->path[0]->y, map->path[0]->x);
	}
	initEnemyPath(getMapEnemys(map), map->path, getMapPathCount(map));
}

int isWaveEnd(Map *map)
{
	if(getMapEnemys(map)->nb == 0)
		return 1;
	return 0;
}

Cell *getCellFromXY(Map *map, int x, int y)
{
	return map->grid[y][x];
}

int isCellBuildable(Cell *c)
{
	return getCellBuild(c);
}

void initEnemyPath(EnsEnemy *enemys, Coord *path[255], int pathCount)
{
	int i,j;

	for (i=0; i<enemys->nb; i++) 
	{
		for (j=0; j<pathCount; j++) 
		{
			enemys->tab[i]->path[j] = path[j];
			enemys->tab[i]->pathCount = pathCount;
		}
	}
}

void freeMap(Map *map)
{
	int i,j;
	freeTowers(getMapTowers(map));
	free(map->towers);
	for(i=0;i<getMapPathCount(map);i++)
	{
		free(map->path[i]);
	}
	Coord dim = getMapDim(map);
	for (i=0; i<dim.x; i++) 
	{
		for (j=0; j<dim.y; j++) 
		{
			free(map->grid[i][j]);
		}
	}
	freeEnemys(getMapEnemys(map));
	free(map->enemys);
	free(map);
}

void setMapEnemys(Map *map, EnsEnemy *enemys)
{
	map->enemys = enemys;
}

EnsEnemy* getMapEnemys(const Map *map)
{
	return map->enemys;
}

void setMapTowers(Map *map, EnsTower *towers)
{
	map->towers = towers;
}
EnsTower* getMapTowers(const Map *map)
{
	return map->towers;
}

void setMapDim(Map *map, int x, int y)
{
	map->dimY = y;
	map->dimX = x;
}
Coord getMapDim(const Map *map)
{
	Coord c;
	c.x = map->dimX;
	c.y = map->dimY;
	return c;
}

void setMapPathCount(Map *map, int pathCount)
{
	map->pathCount = pathCount;
}
int getMapPathCount(const Map *map)
{
	return map->pathCount;
}

void setMapStart(Map *map, Coord *c)
{
	map->start = c;
}
Coord getMapStart(const Map *map)
{
	return *map->start;
}

void setMapEnd(Map *map, Coord *c)
{
	map->end = c;
}
Coord getMapEnd(const Map *map)
{
	return *map->end;
}

void setMapLife(Map *map, int life)
{
	map->life = life;
}
int getMapLife(const Map *map)
{
	return map->life;
}

void setMapWave(Map *map, int wave)
{
	map->wave = wave;
}
int getMapWave(const Map *map)
{
	return map->wave;
}

void setMapGold(Map *map, int gold)
{
	map->gold = gold;
}
int getMapGold(const Map *map)
{
	return map->gold;
}

void setCellEntity(Cell *c, Tower *tower)
{
	c->entity = tower;
}
Tower *getCellEntity(const Cell *c)
{
	return c->entity;
}

void setCellBuild(Cell *c, int build)
{
	c->build = build;
}
int getCellBuild(const Cell *c)
{
	return c->build;
}

void setCellPath(Cell *c, int path)
{
	c->path = path;
}
int getCellPath(const Cell *c)
{
	return c->path;
}

void setCellBegin(Cell *c, int begin)
{
	c->beginP = begin;
}
int getCellBegin(const Cell *c
	){
		return c->beginP;
}

void setCellEnd(Cell *c, int end)
{
	c->endP = end;
}
int getCellEnd(const Cell *c)
{
	return c->endP;
}

void setCellPosition(Cell *c, Coord *pos)
{
	c->position = *pos;
}
Coord getCellPosition(const Cell *c)
{
	return c->position;
}
