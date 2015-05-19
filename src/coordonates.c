
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "coordonates.h"

double getCoordAbs (const Coord* v)
{
    return v->x;
}

double getCoordOrd (const Coord* v)
{
    return v->y;
}

Coord* newCoord(double abs, double ord)
{
	Coord* C;
    C = malloc(sizeof(Coord));
    C->x = abs;
    C->y = ord;
    return C;
 }
   
   

Coord* oppositeCoord(const Coord* v)
{
	Coord* a;
    a = malloc(sizeof(Coord));
	initCoord(a);
	setCoordX(a, -(v->x));
	setCoordY(a, -(v->y));
	return a;
}

void initCoord (Coord *v)
{
    v->x = 0;
    v->y = 0;
}

void setCoordX (Coord* v, double x)
{
    v->x= x;
}

void setCoordY (Coord* v,double y)
{
    v->y= y;
}


void multiplyCoord(Coord* v,double coeff)
{
    v->x = v->x * coeff;
    v->y = v->y * coeff;
}
Coord multipliedCoord(Coord* v,double coeff)
{
	Coord w;
    w.x = v->x * coeff;
    w.y = v->y * coeff;
    return w;
}
	

void addCoords (Coord* u, const Coord* v)
{
    double sumOrd = u->y + v->y;
    double sumAbs = u->x + v->x;
    setCoordonates(u, sumAbs, sumOrd);
}


void subCoords (Coord* u, const Coord* v)
{
    double sumOrd = u->y - v->y;
    double sumAbs = u->x - v->x;
    setCoordonates(u, sumAbs, sumOrd);
}


double getCoordNorm( Coord* v)
{
    return sqrt((v->x*v->x) + (v->y*v->y));
}

void moveCoordtoLeft(Coord* v)
{	
	Coord left;
	setCoordonates(&left, -1.0, 0.0);
    addCoords(v, &left); 
}

void moveCoordtoRight(Coord* v)
{
    Coord right;
    setCoordonates(&right, 1.0,0.0);
    addCoords(v, &right);
}

void moveCoordtoUp(Coord* v)
{	
	Coord up;
    setCoordonates(&up,0.0,-1.0);
    addCoords(v, &up);
}

void moveCoordtoDown(Coord* v)
{
	Coord down;
	setCoordonates(&down,0.0,1.0);
    addCoords(v, &down);
}

void setCoordonates(Coord* v,double x, double y)
{
    setCoordX(v, x);
    setCoordY(v, y);
}

double getCoordsDistance(Coord uno, Coord dos)
{
	addCoords(&(dos), oppositeCoord(&uno));
	return getCoordNorm(&dos);
}


void normaliseCoord (Coord* coo)
{
	double norm = getCoordNorm(coo);
	double newAbs= getCoordAbs(coo) / norm;
	double newOrd= getCoordOrd(coo) / norm;
	setCoordonates(coo, newAbs,newOrd);
}

void setByNorm(Coord* coo, double norm)
{
	normaliseCoord(coo);
	double newAbs = getCoordAbs(coo) * norm;
	double newOrd = getCoordOrd(coo) * norm;
	setCoordonates(coo, newAbs,newOrd);
}


void freeCoord(Coord* coo)
{
	free(coo);
}

int equalCoords(Coord* a, Coord* b)
{
	if(getCoordAbs(a) == getCoordAbs(b) && getCoordOrd(a) == getCoordOrd(b))
	{
		return 1;
    }
		
	return 0;
}


void setCoords(Coord* a, const Coord* b)
{
	setCoordonates (a, b->x, b->y);
}
