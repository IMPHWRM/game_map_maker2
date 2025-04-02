#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define matris_size 50

#include "main.h"
//#include "menu.h"
//#include "editor.h"
//#include "entity.h"

int main(int argc,char* argv[])
{
	//init SDL
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);

	prog_state state={editor,nothing};
	int running=1;
	while(running)
	{
		switch(state.type)
		{
			case menu:
				printf("Lauching menu...\n");
				//state=menu_loop();
				printf("Quit menu.\n");
				break;
			case editor:
				printf("Lauching enditor...\n");
				state=editor_loop(NULL);
				printf("Quit editor.\n");
				break;
			case end:
				printf("End programe.\n");
				running=0;
				break;
			default:
				running=0;
				printf("Error code=%d.\nEnd programe.\n",state.error);
		}
		printf("Switching state.\n");
	}
	IMG_Quit();
	SDL_Quit();
	return state.error;
}
