#ifndef VECTEUR_H
#define VECTEUR_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct sVector
{
    double x;
    double y;
};
typedef struct sVector Vector;

/**
 @brief Rend l'abscisse du vecteur
 @param v le vecteur dont on cherche l'abscisse
 @return L'attribut x du vecteur
 */
double getVectorAbs (const Vector *v);

/**
 @brief Rend l'ordonnée du vecteur
 @param v le vecteur dont on cherche l'ordonnée
 @return L'attribut y du vecteur
 */
double  getVectorOrd (const Vector *v);

/**
 @brief Initialise un vecteur avec comme coordonnées (0,0)
 @param v le nouveau vecteur à initialiser
 */
void initVector (Vector *v);

/**
 @brief modifie l'ordonnée du vecteur
 @param v le vecteur dont on modifie l'ordonnée
 o la nouvelle ordonnée
 */
void setVectorOrd (Vector* v, double o);

/**
 @brief Modifie l'abscisse du vecteur
 @param v le vecteur dont on modifie l'abscisse
 a la nouvelle abscisse
 */
void setVectorAbs (Vector* v, double a);

/**
 @brief Modifie l'abscisse et l'ordonnée du vecteur
 @param v vecteur à modifier, abs la nouvelle abscisse, ord la nouvelle ordonnée
 */
void setVectorcoord(Vector* v,double abs, double ord);

/**
 @brief Multiplie le vecteur par un scalaire
 @param v le vecteur qu'on modifie
 */
void multiplyVector (Vector* v, double coeff);

/**
 @brief Additionne deux vecteurs entre eux
 @param u et v les deux vecteurs à aditionner
 @return Le vecteur somme
 */
Vector addVectors (const Vector* u, const Vector* v);

/**
 @brief rend la norme d'un vecteur
 @param v le vecteur dont on veut la norme
 */
double getVectorNorm(const Vector* v);

/**
 @brief Dirige un vecteur vers la gauche tout en conservant sa norme
 @param v le vectuer à rediriger
 */
void setVectortoLeft(Vector* v);

/**
 @brief Dirige un vecteur vers la droite tout en conseravtn sa norme
 @param v le vectuer à rediriger
 */
void setVectortoRight(Vector * v);

/**
 @brief Dirige un vecteur vers le haut tout en conservant sa norme
 @param v le vecteur à rediriger
 */
void setVectortoUp(Vector *v);

/**
 @brief Dirige un vecteru vers le bas
 @param v le vecteur à rediriger
 */
void setVectortoDown(Vector* v);





#endif
