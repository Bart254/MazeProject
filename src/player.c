#include "../headers/player.h"
#include "../headers/angle.h"
#include <math.h>
player_t player;

/**
 * create_player - initializes all player's attributes
 * @screen_w: width of the screen
 */
void create_player(int screen_w)
{
	double rad;

	player.speed = 0.05;
	player.turn_angle = 1.0;
	player.pos_x = 10;
	player.pos_y = 10;
	player.h = 0.5;
	player.fov = 66.7;
	player.aov = 0;

	/* converts player's fov to radians */
	rad = angle_to_radian(player.fov / 2);

	player.dist_to_plane = (screen_w / 2) / tan(rad);
	player.move_forward = move_forward;
	player.move_back = move_backward;
	player.turn_right = turn_right;
	player.turn_left = turn_left;
}
