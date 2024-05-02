#include "../headers/src.h"
#include "../headers/player.h"

/**
 * poll_events - checks events passed to the program
 * @event: event passed to the program
 * @keys: array of key values
 *
 * Function is called when a key is pressed or released
 * It then executes the logic based on the switch-case
 *
 * Return: 1 to quit sdl session, 0 to keep the session
 */
int poll_events(SDL_Event event, bool *keys)
{
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				return (1);
			case SDL_KEYDOWN:
				if (event.key.keysym.scancode == 0x29)
					return (1);
				handle_down_event(event, keys);
				break;
			case SDL_KEYUP:
				handle_up_event(event, keys);
				break;
			case SDL_MOUSEMOTION:
				handle_mouse_event(event);
				break;
		}
	}
	return (0);
}


/**
 * handle_down_event - handles events passed when key is pressed
 * @event: event passed to the program
 * @keys: array of key values
 * Handle events include some cases that update player's attributes
 */
void handle_down_event(SDL_Event event, bool *keys) 
{
	switch (event.key.keysym.sym)
	{
		case SDLK_w:
			keys[0] = true;
			break;
		case SDLK_s:
			keys[1] = true;
			break;
		case SDLK_a:
			keys[2] = true;
			break;
		case SDLK_d:
			keys[3] = true;
			break;
		case SDLK_m:
			keys[4] = true;
			break;
		case SDLK_x:
			keys[4] = false;
			break;
	}
}

/**
 * handle_up_event - handles events passed on key release
 * @event: event passed to the program
 * @keys: array of key values
 * Handle events include some cases that update player's attributes
 */
void handle_up_event(SDL_Event event, bool *keys) 
{
	switch (event.key.keysym.sym)
	{
		case SDLK_w:
			keys[0] = false;
			break;
		case SDLK_s:
			keys[1] = false;
			break;
		case SDLK_a:
			keys[2] = false;
			break;
		case SDLK_d:
			keys[3] = false;
			break;
	}
}

/**
 * check_keys - moves the player according to key values
 * @key: bool array of key values
 */
void check_keys(bool *keys, SDL_Renderer *renderer, screen_t screen)
{
	if (keys[4])
		draw_minimap(renderer, screen.h, screen.w);
	if (keys[0])
	{       
		if (keys[2])
		{
			player.move_forward();
			player.turn_left();
		}
		else if (keys[3])
		{
			player.move_forward();
			player.turn_right();
		}
		else
			player.move_forward();
	}
	else if (keys[1])
	{
		if (keys[2])
		{
			player.move_back();
			player.turn_left();
		}
		else if (keys[3])
		{
			player.move_back();
			player.turn_right();
		}
		else
			player.move_back();
	}
	else if (keys[2])
		player.turn_left();
	else if (keys[3])
		player.turn_right();
}

/**
 * handle_mouse_event - handles mouse motion
 * @event: mouse event passed to the program
 */
void handle_mouse_event(SDL_Event event)
{
	if (event.motion.xrel > 0)
		player.turn_right();
	else if (event.motion.xrel < 0)
		player.turn_left();
}
