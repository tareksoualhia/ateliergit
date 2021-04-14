#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "perso.h"

void initialisePerso(perso * p){
int vi,sc;
vi=initTextvie(&p->vie);
sc=initTextscore(&p->score);

p->image=IMG_Load("perso.png");
	Uint32 color=SDL_MapRGB(p->image->format, 255, 255, 255);
	SDL_SetColorKey(p->image, SDL_SRCCOLORKEY,color);
p->position.x=0;
p->position.y=700;

p->frame.w=100;
p->frame.h=100;
p->frame.x=0;
p->frame.y=0;

p->curframe=0;
p->running=1;
p->direction=0;
p->previousmvt=0;

p->v_x = 4;
p->v_grav = 0.3;
p->v_saut = -6.5;
p->v_y = p->v_saut;

p->acceleration=5;
p->vitesse=0;


}


void afficherPerso (perso * p,SDL_Surface *screen)
{
	displayvie(p->vie,screen);
	displayscore(p->score,screen);
	SDL_BlitSurface(p->image,&p->frame,screen,&p->position);     
}




void freesurf(SDL_Surface *img){
SDL_FreeSurface(img);

}


void saut_perso(perso * p)
{	
if(p->position.y<700){
   p->position.x += p->v_x;
   p->position.y+= p->v_y;
   p->v_y += p->v_grav;
   
  if (p->position.y> 700)
    p->v_y = p->v_saut;}

}


int moveperso(perso *p ,SDL_Surface* screen,SDL_Event ev)
{  
  if(p->direction != p->previousmvt)
	{
		p->direction=0;// la yemshy la 3al imine o la 3al isar 
		p->previousmvt = p->direction;
	}
switch(ev.type)
{
case SDL_QUIT:
return p->running =0;
break;

case SDL_KEYDOWN:
 {
switch (ev.key.keysym.sym)
 {
   case SDLK_ESCAPE:
   return p->running =0;
   break;
   case SDLK_s://ken l position ta3 l perso akal mn 200 donc thabto hata lin yousel lel 200 bel "S"
    while(p->position.y<700) 
    { 
     p->position.y+=3;
    }
     break;
   
   case SDLK_d:
   p->position.x+=p->vitesse;
   p->direction=1;
   
  break;
   case SDLK_q:
   p->position.x-=p->vitesse;
   p->direction=2;
   
    break;
   case SDLK_SPACE:
   p->position.y-=2;

    break;
  case SDLK_UP:
      	 SDL_Delay(10);
       
         p->vitesse+=p->acceleration;
         p->position.x+=p->vitesse;
         p->direction=1;
         if(p->vitesse>=30)
         {
          p->vitesse=30;
         }
            break;
         
              case SDLK_DOWN:
               
                p->vitesse=0; 
               
                break;
 
}

}

}

saut_perso(p);




}

void animationperso(perso *p ,SDL_Surface* screen){



if(p->direction==1)
{
   p->frame.y=0;
   p->curframe++;
    if(p->curframe>=4)
   {
       p->curframe=0;
   }
       p->frame.x=p->curframe * p->frame.w;  
  

}
else
if(p->direction==2)
{ 
  p->frame.y=100;
 p->curframe++;
    if(p->curframe>=4)
   {
       p->curframe=0;
   }
       p->frame.x=p->curframe * p->frame.w;  
  

}
else 
if(p->direction==0)
{

	p->frame.x=0;

}

}



   
