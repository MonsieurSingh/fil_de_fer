//
//  old.c
//  fil_de_fer
//
//  Created by Teghjyot Singh on 26/6/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "minilibx_macos/mlx.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_point {
	float x;
	float y;
	float z;
}	t_point;

typedef struct s_matrix {
	float m[4][4];
}	t_matrix;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < 1920 && y >= 0 && y < 1200) {
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

t_point	apply_matrix(t_point p, t_matrix matrix)
{
	t_point result;

	result.x = matrix.m[0][0] * p.x + matrix.m[0][1] * p.y + matrix.m[0][2] * p.z + matrix.m[0][3];
	result.y = matrix.m[1][0] * p.x + matrix.m[1][1] * p.y + matrix.m[1][2] * p.z + matrix.m[1][3];
	result.z = matrix.m[2][0] * p.x + matrix.m[2][1] * p.y + matrix.m[2][2] * p.z + matrix.m[2][3];
	return result;
}

t_matrix create_isometric_matrix(void)
{
	float angle_x = M_PI / 6; // 30 degrees
	float angle_y = M_PI / 4; // 45 degrees

	t_matrix matrix = {{
		{cos(angle_y), sin(angle_y) * sin(angle_x), 0, 0},
		{0, cos(angle_x), 0, 0},
		{sin(angle_y), -cos(angle_y) * sin(angle_x), 0, 0},
		{0, 0, 0, 1}
	}};
	return matrix;
}

t_matrix create_translation_matrix(float tx, float ty, float tz)
{
	t_matrix matrix = {{
		{1, 0, 0, tx},
		{0, 1, 0, ty},
		{0, 0, 1, tz},
		{0, 0, 0, 1}
	}};
	return matrix;
}

t_matrix create_rotation_matrix_x(float angle)
{
	t_matrix matrix = {{
		{1, 0, 0, 0},
		{0, cos(angle), -sin(angle), 0},
		{0, sin(angle), cos(angle), 0},
		{0, 0, 0, 1}
	}};
	return matrix;
}

t_matrix create_rotation_matrix_y(float angle)
{
	t_matrix matrix = {{
		{cos(angle), 0, sin(angle), 0},
		{0, 1, 0, 0},
		{-sin(angle), 0, cos(angle), 0},
		{0, 0, 0, 1}
	}};
	return matrix;
}

t_matrix create_rotation_matrix_z(float angle)
{
	t_matrix matrix = {{
		{cos(angle), -sin(angle), 0, 0},
		{sin(angle), cos(angle), 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1}
	}};
	return matrix;
}

t_matrix create_scaling_matrix(float sx, float sy, float sz)
{
	t_matrix matrix = {{
		{sx, 0, 0, 0},
		{0, sy, 0, 0},
		{0, 0, sz, 0},
		{0, 0, 0, 1}
	}};
	return matrix;
}

#define MAP_WIDTH 19
#define MAP_HEIGHT 11

int height_map[MAP_HEIGHT][MAP_WIDTH] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0,10,10, 0, 0,10,10, 0, 0, 0,10,10,10,10,10, 0, 0, 0},
	{0, 0,10,10, 0, 0,10,10, 0, 0, 0, 0, 0, 0, 0,10,10, 0, 0},
	{0, 0,10,10, 0, 0,10,10, 0, 0, 0, 0, 0, 0, 0,10,10, 0, 0},
	{0, 0,10,10,10,10,10,10, 0, 0, 0, 0,10,10,10,10, 0, 0, 0},
	{0, 0, 0,10,10,10,10,10, 0, 0, 0,10,10, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0,10,10, 0, 0, 0,10,10, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0,10,10, 0, 0, 0,10,10,10,10,10,10, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	const int	width = 1920;
	const int	height = 1200;
	const int	grid_size = 50; // Size of each grid cell
	int		x;
	int		y;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, width, height, "Isometric Grid of Pixels");
	img.img = mlx_new_image(mlx, width, height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);

	// Define isometric transformation matrix
	t_matrix isometric_matrix = create_isometric_matrix();
	int	color = 0x00FFFFFF;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			my_mlx_pixel_put(&img, x, y, color);
		}
	}

	for (y = 0; y < MAP_HEIGHT; y++)
	{
		for (x = 0; x < MAP_WIDTH; x++)
		{
			t_point p = {x * grid_size - width / 2, y * grid_size - height / 2, height_map[y][x]};

			// Apply isometric transformation
			p = apply_matrix(p, isometric_matrix);
			t_matrix transformed = create_translation_matrix(0.0f, height_map[y][x] * 2, 0.0f);
			p = apply_matrix(p, transformed);


			// Offset back to the window center
			p.x += width / 2;
			p.y += height / 2;

			my_mlx_pixel_put(&img, p.x, p.y, 0x00000000); // Red color
		}
	}

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
