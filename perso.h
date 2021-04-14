#ifndef perso_H
#define perso_H
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "utilitaire.h"

typedef struct {
	SDL_Rect position;
        SDL_Rect frame;
	SDL_Surface * image;
        int curframe;
        Text vie;
	int direction; 
	Text score; 
        int running;
        int previousmvt;
        double acceleration;
        double decelere;
        double vitesse;
        double v_x;
    	double v_grav ;
    	double v_saut ;
    	double v_y ;

	
	
}perso;






void initialisePerso(perso * p);
void afficherPerso (perso * p,SDL_Surface *screen);
void freesurf(SDL_Surface *img);
void saut_perso(perso *p);
int moveperso(perso *p ,SDL_Surface* screen,SDL_Event event);
void animationperso(perso *p ,SDL_Surface* screen);





#endif
