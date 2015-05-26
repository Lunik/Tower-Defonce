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
 @param v Pointeur sur Coord La Coord dont on cherche l'abscisse
 @return L'attribut x du vecteur
 */
double getCoordAbs (const Coord *v);

/**
 @brief Rend l'ordonnée du vecteur
 @param v Pointeur sur Coord La Coord dont on cherche l'ordonnée
 @return L'attribut y du vecteur
 */
double  getCoordOrd (const Coord *v);

/**
 @brief Initialise un vecteur avec comme coordonnées (0,0)
 @param v Pointeur sur Coord La Coord à initialiser
 */
void initCoord (Coord *v);

/**
 @brief Modifie l'ordonnée du vecteur
 @param v Pointeur sur Coord La Coord dont on modifie l'ordonnée
 o la nouvelle ordonnée
 */
void setCoordY (Coord* v, double y);

/**
 @brief Modifie l'abscisse du vecteur
 @param v Pointeur sur Coord La Coord dont on modifie l'abscisse
 @param x double La nouvelle abscisse
 */
void setCoordX (Coord* v, double x);

/**
 @brief Modifie l'abscisse et l'ordonnée du vecteur
 @param v Pointeur sur Coord La Coord à modifier
 @param x double La nouvelle abscisse
 @param y double La nouvelle ordonnée
 */
void setCoordonates(Coord* v,double x, double y);

/**
 @brief Multiplie les valeurs d'une Coord par un scalaire
 @param v Pointeur sur Coord La Coord à modifier
 @param coeff double Le scalaire par lequel on multiplie
 */
void multiplyCoord (Coord* v, double coeff);

/**
 @brief Additionne une Coord à une autre
 @param u Pointeur sur Coord La Coord à laquelle on ajoute
 @param v const Pointeur sur Coord La Coord à ajouter
 */
void addCoords (Coord* u, const Coord* v);

/**
 @brief Rend la norme d'un vecteur
 @param v Pointeur surCoord La Coord dont on veut la norme
 */
double getCoordNorm( Coord* v);

/**
 @brief Enlève 1 à l'abscisse
 @param v Pointeur sur Coord La Coord modifiée
 */
void moveCoordtoLeft(Coord* v);

/**
 @brief Rajoute 1 à l'abscisse
 @param v Pointeur sur Coord La Coord modifiée
 */
void moveCoordtoRight(Coord * v);

/**
 @brief Enlève 1 à l'ordonnée
 @param v Pointeur sur Coord La Coord modifiée
 */
void moveCoordtoUp(Coord *v);

/**
 @brief Rajoute 1 à l'ordonnée
 @param v Pointeur sur Coord La Coord modifiée
 */
void moveCoordtoDown(Coord* v);

/**
 @brief Renvoie la coordonees inverse
 @param v Pointeur sur Coord
 @return Pointeur sur Coord
 */
Coord* oppositeCoord(const Coord* v);

/**
 @brief Renvoie la distance entre deux coordonnes
 @param uno Pointeur sur Coord
 @param dos Pointeur sur Coord
 @return Distance entre les deux Coord
 */
double getCoordsDistance(Coord uno, Coord dos);
/**
 @brief  Normalise une Coord. (met le vecteur de la Coord à une norme de 1
 @param coo Pointeur sur Coord les coordonnées à modifier
 */
void normaliseCoord (Coord* coo);

/**
 @brief Garde la direction de coordonnées, change la norme
 @param coo Pointeur sur Coord Coordonnées à modifier
 @param norm double La nouvelle norme des coordonnées
 */
void setByNorm(Coord* coo, double norm);

/**
 @brief Alloue la place pour une nouvelle cordonnée et l'initialise aux coodonnées voulues
 @param abs double Le X de la nouvelle Coord
 @param ord double Le Y de la nouvelle Coord
 @return Pointeur sur la nouvelle Coord
 */
Coord* newCoord(double abs, double ord);

/**
 @brief Multiplie les valeurs d'une Coord
 @param v Pointeur sur Coord La Coord à modifier
 @param coeff double Le nombre par lequel on multiplie les valeurs
 @return Une Coord avec les nouvelles valeurs
 */
Coord multipliedCoord(Coord* v,double coeff);

/**
 @brief Libère l'espace alloué pour une Coord
 @param coo Pointeur sur Coord Coordonnées que l'on supprime
 */
void freeCoord(Coord* coo);

/**
 @brief Vérifie si deux Coord sont égales
 @param a Pointeur sur Coord
 @param b Pointeur sur Coord
 @return 1 si vrai, 0 si faux
 */
int equalCoords(Coord* a, Coord* b);

/**
 @brief Soustrait les valeurs d'une Coord à une autre
 @param u Pointeur sur Coord La Coord que l'on modifie
 @param v Coord la Coord que l'on soustrait
 */
void subCoord (Coord* u, const Coord v);
/**
 @brief Met les valeurs d'une Coord dans une autre
 @param a Pointeur sur Coord La Coord qu'on modifie
 @param b Coord La Coord que'on copie
 */
void setCoord(Coord* a, const Coord b);

#endif
