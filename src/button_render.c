#include <SDL2/SDL.h>
#include "button.h"

int button_render(SDL_Renderer* renderer,char* button_name,SDL_Rect dst)
{
	SDL_SetRenderDrawColor(renderer,75,75,75,255);
	SDL_RenderFillRect(renderer,&dst);
	dst.w=9;
	dst.h=12;
	SDL_Rect src={0,0,9,12};
	SDL_RenderCopy(renderer,button_texture,&src,&dst);
	return 0;
}
