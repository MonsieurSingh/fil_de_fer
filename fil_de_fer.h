//
//  fil_de_fer.h
//  fil_de_fer
//
//  Created by Teghjyot Singh on 26/6/2024.
//

#ifndef fil_de_fer_h
#define fil_de_fer_h

#include "libft/libft.h"
#include "minilibx_macos/mlx.h"
#include "libft/ft_printf.h"
#include "libft/get_next_line.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		map_width;
	int		map_height;
	char	***char_map;
}	t_data;

typedef struct s_point {
	float x;
	float y;
	float z;
}	t_point;

typedef struct s_matrix {
	float m[4][4];
}	t_matrix;

int		verify(int argc, const char *argv[], t_data	*data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif /* fil_de_fer_h */
