#include "../headers/player.h"
#include "../headers/angle.h"
#include "../headers/map.h"
#include <math.h>

/**
 * move_forward - moves the player forward
 */
void move_forward(void)
{
	double x_temp, y_temp, new_x, new_y;

	new_x = player.pos_x;
	new_y = player.pos_y;
	x_temp = player.speed * cos(angle_to_radian(player.aov));
	y_temp = player.speed * sin(angle_to_radian(player.aov));

	if ((is_right(player.aov) && x_temp < 0) ||
	     (is_left(player.aov) && x_temp > 0))
		x_temp = -x_temp;

	if ((is_up(player.aov) && y_temp > 0) ||
	     (is_down(player.aov) && y_temp < 0))
		y_temp = -y_temp;

	new_x += x_temp;
	new_y += y_temp;

	if (!check_collision(new_x, new_y))
	{
		player.pos_x = new_x;
		player.pos_y = new_y;
	}
}

/**
 * move_backward - moves the player back
 */
void move_backward(void)
{
	double x_temp, y_temp, new_x, new_y;

	new_x = player.pos_x;
	new_y = player.pos_y;
	x_temp = player.speed * cos(angle_to_radian(player.aov));
	y_temp = player.speed * sin(angle_to_radian(player.aov));

	if ((is_right(player.aov) && x_temp < 0) ||
	     (is_left(player.aov) && x_temp > 0))
		x_temp = -x_temp;

	if ((is_up(player.aov) && y_temp > 0) ||
	     (is_down(player.aov) && y_temp < 0))
		y_temp = -y_temp;

	new_x -= x_temp;
	new_y -= y_temp;

	if (!check_collision(new_x, new_y))
	{
		player.pos_x = new_x;
		player.pos_y = new_y;
	}
}

/**
 * check_collision - checks if player has hit a wall
 * @x: players's new x coordinate
 * @y: player's new y coordinate
 * Return: 1 if a wall has been hit, 0 if no wall is hit
 */
int check_collision(int x, int y)
{
	if (x < 0 || x >= map.w ||
	    y < 0 || y >= map.h
	    || map.pos[y][x])
		return (1);
	return (0);
}

/**
 * turn_right - turns to the right
 */
void turn_right(void)
{
	player.aov -= player.turn_angle;
	if (player.aov < 0)
		player.aov += 360;
}

/**
 * turn_left - turns to the left
 */
void turn_left(void)
{
	player.aov += player.turn_angle;
	if (player.aov > 360)
		player.aov -= 360;
}
