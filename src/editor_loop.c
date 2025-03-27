#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#include "main.h"
#include "button.h"

prog_state editor_loop(void)
{
	SDL_Window* window=SDL_CreateWindow("editor",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	SDL_Renderer* renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer,50,50,50,255);

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
		SDL_Rect dst={0,0,100,100};
		button_render(renderer,NULL,dst);
		SDL_RenderPresent(renderer);
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	return return_value;
}
