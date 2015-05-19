#include "sdlFct.h"
const int TAILLE_SPRITE=32;

SDL_Surface *sdlLoadImage(const char* filename){
    /* Temporary storage for the image that's loaded */
    SDL_Surface* loadedImage = IMG_Load( filename );
    
    /* Return the optimized image */
    return loadedImage;
}


void sdlApplySurface(SDL_Surface* source, SDL_Surface* destination, double x, double y){
    /* Make a temporary rectangle to hold the offsets */
    SDL_Rect offset;

    /* Give the offsets to the rectangle */
    offset.x = (x*TAILLE_SPRITE)+TAILLE_SPRITE;
    offset.y = (y*TAILLE_SPRITE)+TAILLE_SPRITE;
    
    /* Blit the suace */
    SDL_BlitSurface( source, NULL, destination, &offset );
}

void sdlApplyText(SDL_Surface *destination, double x, double y, char text[255], SDL_Color color, TTF_Font *police){
	SDL_Surface *surface;
	surface = textToSurface(text, color, police);
	sdlApplySurface(surface, destination, x, y);
	SDL_FreeSurface(surface);
}

SDL_Surface *textToSurface(char txt[255], SDL_Color color, TTF_Font *police){
    SDL_Surface *s = TTF_RenderText_Blended(police, txt, color);
    return s;
}

Sprite *newSprite(){
    Sprite *s;
    s = malloc(sizeof(Sprite));
    setSpriteNb(s,0);
    setSpriteActual(s,0);
    setSpriteTimer(s,0,1);
    return s;
}
void addSprite(Sprite *s, char *path){
    s->sprites[s->nb] = sdlLoadImage(path);
    assert(s->sprites[s->nb] !=NULL);
    setSpriteNb(s,getSpriteNb(s)+1);
}

void updateSprite(Sprite *s){
    
    if (getSpriteTimer(s)>0) {
        setSpriteTimer(s,getSpriteTimer(s)-1, getSpriteDefaultTimer(s));
    } else {
        setSpriteTimer(s, getSpriteTimer(s), getSpriteDefaultTimer(s));
        setSpriteActual(s, getSpriteActual(s)+1);
        if(getSpriteActual(s) >= getSpriteNb(s))
            resetSprite(s);
    }
}

void resetSprite(Sprite *s){
    setSpriteTimer(s, getSpriteTimer(s), getSpriteDefaultTimer(s));
    setSpriteActual(s, 0);
}

int getSpriteFromTimer(Sprite *s, int defaultTimer, int timer){
    int iSprite;
    
    iSprite = (int)(getSpriteNb(s)*timer) / defaultTimer;
    
    if (iSprite >= getSpriteNb(s) || iSprite < 0) {
        iSprite = 0;
    }
    return iSprite;
}

void freeSprite(Sprite *s){
    int i;
    for (i=0; i<getSpriteNb(s); i++) {
        SDL_FreeSurface(s->sprites[i]);
    }
}

int getSpriteNb(const Sprite *s){
    return s->nb;
}
void setSpriteNb(Sprite *s, int nb){
    s->nb = nb;
}

int getSpriteActual(const Sprite *s){
    return s->actual;
}
void setSpriteActual(Sprite *s, int actual){
    s->actual = actual;
}

int getSpriteTimer(const Sprite *s){
    return s->timer;
}
int getSpriteDefaultTimer(const Sprite *s){
    return s->defaultTimer;
}

void setSpriteTimer(Sprite *s, int timer, int defaultTimer){
    s->timer = timer;
    s->defaultTimer = defaultTimer;
}






