#include "../headers/src.h"
#include <stdio.h>

/**
 * init_instance - initializes SDL2 environment
 * @instance: pointe to instance struct
 * @screen: screen struct
 * Return: 0 if successful, 1 if unsuccessful
 */
int init_instance(SDL_Instance *instance, screen_t screen)
{
	/* Initiliaze window and renderer */
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		fprintf(stderr, "SDL_Init_Error: %s\n", SDL_GetError());
		return (1);
	}
	instance->window = SDL_CreateWindow("Maze Games",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			screen.w, screen.h, 0);
	if (instance->window == NULL)
	{
		fprintf(stderr, "SDL_CreateWindow_Error: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}
	instance->renderer = SDL_CreateRenderer(instance->window, -1,
			     SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (instance->renderer == NULL)
	{
		fprintf(stderr, "SDL_CreateRenderer_Error: %s\n", SDL_GetError());
		SDL_DestroyWindow(instance->window);
		SDL_Quit();
		return (1);
	}
	if (initialize_png(instance))
		return (1);
	return (0);
}

/**
 * initialize_png - initializes image loading
 * Return: 0 if successful, otherwise 0
 */
int initialize_png(SDL_Instance *instance)
{
	int imgFlags = IMG_INIT_PNG;

	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		fprintf(stderr, "SDL_image could not initialize! SDL_image Error: %s\n",
			IMG_GetError());
		return (1);
	}
	if (load_texture(instance))
		return (1);
	return (0);
}


/**
 * load_texture - creates texture from an image
 * @instance: pointer to instance struct
 * Return: 1 if it fails to create a texture, 0 if it's successful
 */
int load_texture(SDL_Instance *instance)
{
	int i;

	char text[4][40] = {"resources/images/redbrick.png",
	                    "resources/images/eagle.png",
			    "resources/images/bluestone.png",
			    "resources/images/wood.png"
			    };
	for (i = 0; i < 4; i++)
	{
		SDL_Surface *wall = IMG_Load(text[i]);
		if (wall == NULL)
		{
			fprintf(stderr, "Unable to load image! Error: %s\n",
			SDL_GetError());
			return (1);
		}
		instance->texture[i] = SDL_CreateTextureFromSurface(instance->renderer, wall);
		SDL_FreeSurface(wall);
		if (instance->texture[i] == NULL)
		{
			fprintf(stderr, "Unable to create texture! SDL Error: %s\n",
				SDL_GetError());
			return (1);
		}
	}
	return (0);
}
