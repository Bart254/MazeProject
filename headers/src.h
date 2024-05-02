#ifndef SRC_H
#define SRC_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>

/**
 * SDL_Instance - SDL structure
 * @window: SDL2 screen with dimensions
 * @renderer: tool for drawing on the window
 * @texture: texture map
 * @surface: the surface being loaded
 */
typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Texture *texture[4];
	SDL_Texture *sprite[2];
} SDL_Instance;

/**
 * screen_t - struct of the projection plane
 * @w: width of the screen
 * @h: height of screen
 */
typedef struct screen_t {
	int w;
	int h;
} screen_t;

int init_instance(SDL_Instance *instance, screen_t screen);
int initialize_png(SDL_Instance *instance);
int load_texture(SDL_Instance *instance);
void draw_maze(screen_t screen, SDL_Instance instance);

int poll_events(SDL_Event event, bool *keys);
void handle_down_event(SDL_Event event, bool *keys);
void handle_up_event(SDL_Event event, bool *keys);
void handle_mouse_event(SDL_Event event);
void check_keys(bool *key, SDL_Renderer *renderer, screen_t screen);

/* defining colour to be used in my program */
#define PURPLE (SDL_Color) {0, 0, 255, 204}
#define GREEN (SDL_Color) {0, 255, 0, 204}
#define DARK (SDL_Color) {0, 0, 0, 204}
#define WHITE (SDL_Color) {255, 255, 255, 204}
#define V_PURPLE (SDL_Color) {0, 0, 125, 102}
#define V_GREEN (SDL_Color) {0, 125, 0, 102}
#define V_DARK (SDL_Color) {125, 125, 125, 102}
#define V_WHITE (SDL_Color) {125, 125, 125, 102}


void set_color(SDL_Renderer *renderer, SDL_Color color);
void set_wall_color(SDL_Renderer *render, int x, int y, int side);
void set_horizontal_color(SDL_Renderer *renderer, int x, int y);
void set_vertical_color(SDL_Renderer *renderer, int x, int y);

/**
 * minimap_t - structure of minimap
 * @w: width of the minimap
 * @h: height
 * @x_off: distance from the left margin of screen
 * @y_off: distance from the top of the screen
 * @size_x: width of one cell
 * @size_y: height of one cell
 * @scale: fraction of the screen
 */
typedef struct minimap_t {
	int w;
	int h;
	int x_off;
	int y_off;
	double size_x;
	double size_y;
	double scale;
} minimap_t;

void draw_minimap(SDL_Renderer *renderer, int h, int w);
void draw_miniplayer(SDL_Renderer *renderer, minimap_t mm);

#endif /* SRC_H */
