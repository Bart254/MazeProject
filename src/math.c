#include <stdbool.h>
#include <math.h>

/**
 * is_right - checks if the angle is on the right
 * @angle: angle to check
 * Return: true if it's on the right, otherwise false
 */
bool is_right(double angle)
{
	if (angle < 90 || angle > 270)
		return (true);
	return (false);
}

/**
 * is_left - checks if the angle is on the left
 * @angle: angle to check
 * Return: true if on the left, otherwise false
 */
bool is_left(double angle)
{
	if (angle > 90 && angle < 270)
		return (true);
	return (false);
}

/**
 * is_up - checks if the angle is up
 * @angle: angle to check
 */
bool is_up(double angle)
{
	if (angle < 180)
		return (true);
	return (false);
}

/**
 * is_down - checks if the angle is down
 * @angle: angle to check
 */
bool is_down(double angle)
{
	if (angle > 180)
		return (true);
	return (false);
}

/**
 * angle_to_radian - converts an angle to its equivalent radian value
 * @alpha: angle to be converted to radian
 * Return: radian value of the angle
 */
double angle_to_radian(double alpha)
{
	double converter;

	converter = M_PI / 180;
	return ((alpha + 0.001) * converter);
}
