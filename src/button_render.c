#include <SDL2/SDL.h>
#include "button.h"

int button_render(SDL_Renderer* renderer,char* button_name,SDL_Texture* font_texture,SDL_Rect dst)
{
	SDL_SetRenderDrawColor(renderer,75,75,75,255);
	SDL_RenderFillRect(renderer,&dst);
	dst.w=12;
	dst.h=18;
	SDL_Rect src={0,0,12,18};
	int i=0;
	while(button_name[i]!=0)
	{
		if(button_name[i]==32)
			src.x=-12;
		else if(button_name[i]>='a' && button_name[i]<='z')
			src.x=(button_name[i]-'a')*12;
		SDL_RenderCopy(renderer,font_texture,&src,&dst);
		i++;
		dst.x+=12;
	}
	return 0;
}
