#ifndef SDLFCT_H
#define SDLFCT_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>

typedef struct{
    SDL_Surface *sprites[25];
    int nb;
    int actual;
    int timer;
    int defaultTimer;
} Sprite;

/**
 @brief Applique une surface sur une autre avec une position
 @param source SDL_Surface source
 @param destination SDL_Surface destination
 @param x position en X
 @param y position en y
 */
void sdlApplySurface(SDL_Surface* source, SDL_Surface* destination, double x, double y);

void sdlApplyText(SDL_Surface *destination, double x, double y, char text[255], SDL_Color color, TTF_Font *police);
/**
 @brief Charge une image
 @param filename chemin d'acces à l'image
 @return l'image en SDL_Surface
 */
SDL_Surface *sdlLoadImage(const char* filename);

/**
 @brief Convertie un tableau de char en SDL_Surface
 @param txt chaine de char
 @param color Couleur du texte
 @param police Police du texte
 @return le texte en SDL_Surface
 */
SDL_Surface *textToSurface(char txt[255], SDL_Color color, TTF_Font *police);

/**
@brief Crée une structure Sprite initialisé
@return Pointeur sur Sprite
*/
Sprite *newSprite();

/*
@brief Ajoute une image au Sprite
@param s Pointeur sur Sprite
@param path Chemin du fichier
*/
void addSprite(Sprite *s, char *path);

/*
@brief Met à jour le sprite
@param s Pointeur sur Sprite
*/
void updateSprite(Sprite *s);

/*
@brief Remet le sprite à zero
@param s Pointeur sur Sprite
*/
void resetSprite(Sprite *s);

/*
@brief Renvoi le numero du sprite conrespondant au timer (simple produit en croix: numeroSprite = (nbSprites * timer) / defaultTimer)
@param s Pointeur sur Sprite
@param defaultTimer Timer de base
@param timer Timer courrant
@return int Le numero de sprite correspondant
*/
int getSpriteFromTimer(Sprite *s, int defaultTimer, int timer);

/*
@brief Free une structure sprite
@param s Pointeur sur Sprite
*/
void freeSprite(Sprite *s);

/*
@brief Retourne le nombre d'image dans le sprite
@param s Pointeur sur Sprite
@return int nb d'images
*/
int getSpriteNb(const Sprite *s);
/*
@brief Modifie le nombre d'images dans le sprite
@param s Pointeur sur Sprite
@param nb Nombre à modifier
*/
void setSpriteNb(Sprite *s, int nb);

/*
@brief Retourne numero d'image actuel
@param s Pointeur sur Sprite
@return int numero d'images
*/
int getSpriteActual(const Sprite *s);
/*
@brief Modifie numero d'image actuel
@param s Pointeur sur Sprite
@param actual numero d'images
*/
void setSpriteActual(Sprite *s, int actual);

/*
@brief Retourne Timer du sprite
@param s Pointeur sur Sprite
@return int Timer du sprite
*/
int getSpriteTimer(const Sprite *s);
/*
@brief Retourne le defaultTimer du sprite
@param s Pointeur sur Sprite
@return int dafaultTimer du sprite
*/
int getSpriteDefaultTimer(const Sprite *s);

/*
@brief Modifie le defaultTimer et Timer du sprite
@param s Pointeur sur Sprite
@param timer Timer du Sprite
@param defaultTimer DefaultTimer du Sprite
*/
void setSpriteTimer(Sprite *s, int timer, int defaultTimer);
#endif




