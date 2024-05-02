/* header file for map struct and associated functions */

#ifndef MAP_H
#define MAP_H

/**
 * map_t - structure of the 2D map
 * @w: width of the map
 * @h: height of the map
 */
typedef struct map_t
{
	int **pos;
	int w;
	int h;
	double x_off;
	double y_off;
} map_t;
extern map_t map;

int get_map(void);
int get_rows(char *buffer, int size);
int get_cols(char *buffer, int size);
int create_map(void);
void fill_map(char *buffer, int size);

#endif
