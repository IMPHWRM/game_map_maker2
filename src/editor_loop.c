#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "main.h"
#include "button.h"

prog_state editor_loop(char* map_file_name)
{
	SDL_Window* window=SDL_CreateWindow("editor",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	SDL_Renderer* renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer,50,50,50,255);

	SDL_Surface* image=IMG_Load("font.png");
	SDL_Texture* font_texture=SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);

	SDL_Event event;

	prog_state return_value={end,nothing};
	int running=1;
	while(running)
	{
		while(SDL_PollEvent(&event))
			switch(event.type)
			{
				case SDL_QUIT:
					running=0;
					return_value.type=end;
					break;
			}
		SDL_SetRenderDrawColor(renderer,50,50,50,255);
		SDL_RenderClear(renderer);
	//render
		//bloc render
		if(map_file!=NULL)
		{
			
		}
		//button render
		SDL_Rect dst={0,0,100,100};
		button_render(renderer,"salut mon gas",font_texture,dst);
		SDL_RenderPresent(renderer);
		SDL_Delay(16);
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	return return_value;
}
