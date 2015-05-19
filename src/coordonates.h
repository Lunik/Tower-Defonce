#ifndef COORDONATES_H
#define COORDONATES_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct sCoord
{
    double x;
    double y;
};
typedef struct sCoord Coord;

/**
 @brief Rend l'abscisse du vecteur
 @param v le vecteur dont on cherche l'abscisse
 @return L'attribut x du vecteur
 */
double getCoordAbs (const Coord *v);

/**
 @brief Rend l'ordonnée du vecteur
 @param v le vecteur dont on cherche l'ordonnée
 @return L'attribut y du vecteur
 */
double  getCoordOrd (const Coord *v);

/**
 @brief Initialise un vecteur avec comme coordonnées (0,0)
 @param v le nouveau vecteur à initialiser
 */
void initCoord (Coord *v);

/**
 @brief modifie l'ordonnée du vecteur
 @param v le vecteur dont on modifie l'ordonnée
 o la nouvelle ordonnée
 */
void setCoordY (Coord* v, double y);

/**
 @brief Modifie l'abscisse du vecteur
 @param v le vecteur dont on modifie l'abscisse
 a la nouvelle abscisse
 */
void setCoordX (Coord* v, double x);

/**
 @brief Modifie l'abscisse et l'ordonnée du vecteur
 @param v vecteur à modifier, abs la nouvelle abscisse, ord la nouvelle ordonnée
 */
void setCoordonates(Coord* v,double x, double y);

/**
 @brief Multiplie le vecteur par un scalaire
 @param v le vecteur qu'on modifie
 */
void multiplyCoord (Coord* v, double coeff);

/**
 @brief Additionne deux vecteurs entre eux
 @param u et v les deux vecteurs à aditionner
 @return Le vecteur somme
 */
void addCoords (Coord* u, const Coord* v);

/**
 @brief rend la norme d'un vecteur
 @param v le vecteur dont on veut la norme
 */
double getCoordNorm( Coord* v);

/**
 @brief Dirige un vecteur vers la gauche tout en conservant sa norme
 @param v le vectuer à rediriger
 */
void moveCoordtoLeft(Coord* v);

/**
 @brief Dirige un vecteur vers la droite tout en conseravtn sa norme
 @param v le vectuer à rediriger
 */
void moveCoordtoRight(Coord * v);

/**
 @brief Dirige un vecteur vers le haut tout en conservant sa norme
 @param v le vecteur à rediriger
 */
void moveCoordtoUp(Coord *v);

/**
 @brief Dirige un vecteru vers le bas
 @param v le vecteur à rediriger
 */
void moveCoordtoDown(Coord* v);

/**
 @brief Renvoie la coordonees inverse
 @param v Pointeur sur Coord
 @return Pointeur sur Coord
 */
Coord* oppositeCoord(const Coord* v);

/**
 @brief Revoie la distance entre deux coordonnes
 @param uno Pointeur sur Coord
 @param dos Pointeur sur Coord
 @return Distance entre les deux Coord
 */
double getCoordsDistance(Coord uno, Coord dos);

void normaliseCoord (Coord* coo);

void setByNorm(Coord* coo, double norm);

Coord* newCoord(double abs, double ord);

Coord multipliedCoord(Coord* v,double coeff);

void freeCoord(Coord* coo);

int equalCoords(Coord* a, Coord* b);

void subCoord (Coord* u, const Coord v);

void setCoord(Coord* a, const Coord b);
#endif
