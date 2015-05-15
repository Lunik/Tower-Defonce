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
void sdlApplySurface(SDL_Surface* source, SDL_Surface* destination, int x, int y);

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

Sprite *newSprite();

void addSprite(Sprite *s, char *path);

void updateSprite(Sprite *s);

void resetSprite(Sprite *s);

int getSpriteFromTimer(Sprite *s, int defaultTimer, int timer);

void freeSprite(Sprite *s);

int getSpriteNb(const Sprite *s);
void setSpriteNb(Sprite *s, int nb);

int getSpriteActual(const Sprite *s);
void setSpriteActual(Sprite *s, int actual);

int getSpriteTimer(const Sprite *s);
int getSpriteDefaultTimer(const Sprite *s);

void setSpriteTimer(Sprite *s, int timer, int defaultTimer);
#endif
