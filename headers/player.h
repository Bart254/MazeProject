#ifndef PLAYER_H
#define PLAYER_H

/**
 * player_t - structure of a player
 * @fov: player's field of view
 * @aov: player's viewing angle
 * @pos_x: player's column(x) position on the map
 * @pos_y: player's row(y) position on the map
 */
typedef struct player_t
{
	double h;
	double fov;
	double aov;
	double pos_x;
	double pos_y;
	double dist_to_plane;
	double speed;
	double turn_angle;
	void (*move_forward) ();
	void (*move_back) ();
	void (*turn_left) ();
	void (*turn_right) ();
} player_t;
extern player_t player;

void create_player(int screen_w);
void move_forward(void);
void move_backward(void);
void turn_right(void);
void turn_left(void);
int check_collision(int x, int y);

#endif /* PLAYER_H*/
