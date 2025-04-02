#ifndef MOB_H
#define MOB_H

#include <SDL2/SDL.h>

//if the pos is in 2 direction (exemple : left and top) you can use a pipe
#define right 1
#define bottom 2
#define is_moving 4

struct vct
{
	short x;
	short y;
};
struct fvct
{
	float x;
	float y;
};

#define ENTITY 28
struct entity_struct
{
	struct vct mov_vct;
	struct vct phy_vct;
	SDL_Rect dst;
};

typedef struct 
{
	struct entity_struct entity;
	char pos;
	int heal;
}mob_struct;

#define MOB 36
typedef struct
{
	mob_struct mob;
	int dash_cooldown;
}hero;

//function
mob_struct init_mob(int x,int y,int w,int h,int heal,char pos);
int entity_render(SDL_Renderer* renderer,SDL_Texture* entity_texture,struct entity_struct entity);

#endif
