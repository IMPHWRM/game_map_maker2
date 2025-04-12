#include <stdio.h>
#include <stdlib.h>
short** read_game_map(FILE* map_file,int number_of_differente_entity,char** number_of_entity)
{
	if(map_file==NULL)
	{
		printf("map_file is NULL\n");
		return NULL;
	}
	fseek(map_file,0,SEEK_END);
	int size=ftell(map_file);
	fseek(map_file,0,SEEK_SET);
	
	int x=getc(map_file);
	x*=50;
	short** entity_table=malloc((x+1)*sizeof(short*));
	//entity_table[x]=NULL;
	int y=(getc(map_file));
	if(y==0)
	{
		printf("bloc table is empty in y\n");
		return NULL;
	}
	if(size<=y*x)
	{
		printf("map_file is to smale or do not respect the file format\n");
		return NULL;
	}

	y*=50;
	for(int i=0;i<x+1;i++)
	{
		entity_table[i]=malloc(y);
		printf("malloc ...i%d\n",x+1);
	}
	int actuel_byte=getc(map_file);
	fseek(map_file,actuel_byte,SEEK_SET);
	for(int i=0;i<50;i++)
	{
		for(int j=0;j<50;j++)
		{
			entity_table[i][j]=0;
			entity_table[i][j]=getc(map_file);
			//printf("%c",entity_table[i][j]);
		}
	}
		printf("map_file is to smale or do not respect the file format\n");
	return entity_table;
}
