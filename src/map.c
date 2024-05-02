#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../headers/map.h"
map_t map;

/**
 * get_map - generates a map from file
 * Return: 0 if succesful, otherwise 1
 */
int get_map(void)
{
	int fd, bytes_read;
	char filename[] = "src/maze.txt";
	char buffer[3000];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error opening file %s.\n", filename);
		return (1);
	}
	bytes_read = read(fd, &buffer, sizeof(buffer));
	if (bytes_read < 0)
	{
		fprintf(stderr, "Error reading file %s.\n", filename);
		return (1);
	}

	/* find the map height and width */
	map.h = get_rows(buffer, bytes_read);
	map.w = get_cols(buffer, bytes_read);

	/* allocate memory to store map data */
	if (create_map())
		return (1);

	/* initiliaze the map memory created */
	fill_map(buffer, bytes_read);
	return (0);
}

/**
 * get_rows - returns the number of rows in the file_map
 * @buffer: array of file map characters read
 * @size: number of characters read from the file
 * Return: number of rows in the file
 */
int get_rows(char *buffer, int size)
{
	int r, i;

	if (!buffer || !buffer[0])
		return (0);

	r = 0;
	for (i = 0; i < size; i++)
	{
		if (buffer[i] == '\n')
			r++;
	}
	return (r);
}

/**
 * get_cols - returns the number of columns in the file_map
 * @buffer: array of file map characters read
 * @size: number of characters read from the file
 * Return: number of cols in the file
 */
int get_cols(char *buffer, int size)
{
	int col, i;

	if (!buffer || !buffer[0])
		return (0);

	for (col = 0, i = 0; buffer[i] != '\n' && i < size; i++)
		col++;

	return (col);
}

/**
 * create_map - allocates memory for 2D version of the map
 * Return: 0 if successful, otherwise 1
 */
int create_map(void)
{
	int i;

	map.pos = malloc(map.h * sizeof(int *));
	if (!map.pos)
	{
		fprintf(stderr, "Map memory allocation failed\n");
		return (1);
	}
	for (i = 0; i < map.h; i++)
	{
		(map.pos)[i] = malloc(map.w * sizeof(int));
		if ((map.pos)[i] == NULL)
		{
			/*free_map(map);*/
			fprintf(stderr, "Map memory allocation failed\n");
			return (1);
		}
	}

	return (0);
}

/**
 * fill_map - fills the map array
 * @buffer: file data used to load the map
 * @size: size of the characters in the buffer
 */
void fill_map(char *buffer, int size)
{
	int r, c, i;

	for (r = 0, i = 0; r < map.h; r++)
	{
		for (c = 0; c < map.h && i < size; i++)
		{
			if (buffer[i] == '\n')
				continue;
			switch (buffer[i])
			{
				case '1':
					map.pos[r][c] = 1;
					break;
				case '2':
					map.pos[r][c] = 2;
					break;
				case '3':
					map.pos[r][c] = 3;
					break;
				case '4':
					map.pos[r][c] = 4;
					break;
				default:
					map.pos[r][c] = 0;
					break;
			}
			c++;
		}
	}
}
