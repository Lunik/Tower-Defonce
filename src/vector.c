#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "vector.h"

double getVectorAbs (const Vector* v)
{
    return v->x;
}

double getVectorOrd (const Vector* v)
{
    return v->y;
}


void initVector (Vector *v)
{
    v->x = 0;
    v->y = 0;
}

void setVectorAbs (Vector* v, double a)
{
    v->x= a;
}

void setVectorOrd (Vector* v,double o)
{
    v->y= o;
}


void multiplyVector(Vector* v,double coeff)
{
    v->x = v->x * coeff;
    v->y = v->y * coeff;
}

Vector addVectors (const Vector* u, const Vector* v)
{
    Vector sum;
    initVector(&sum);
    int sumOrd = u->y + v->y;
    int sumAbs = u->x + v->x;
    setVectorOrd(&sum, sumOrd);
    setVectorAbs(&sum, sumAbs);
    return sum;
}

double getVectorNorm(const Vector* v)
{
    return sqrt((v->x*v->x) + (v->y*v->y));
}
void setVectortoLeft(Vector* v)
{
    setVectorAbs(v,-getVectorNorm(v));
    setVectorOrd(v, 0);
}

void setVectortoRight(Vector* v)
{
    setVectorAbs(v, getVectorNorm(v));
    setVectorOrd(v,0);
}

void setVectortoUp(Vector* v)
{
    setVectorOrd(v, -getVectorNorm(v));
    setVectorAbs(v, 0);
}

void setVectortoDown(Vector* v)
{
    setVectorOrd(v, getVectorNorm(v));
    setVectorAbs(v, 0);
}

void setVectorcoord(Vector* v,double abs, double ord)
{
    setVectorAbs(v, abs);
    setVectorOrd(v, ord);
}





