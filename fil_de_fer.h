/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil_de_fer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tesingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 23:16:26 by tesingh           #+#    #+#             */
/*   Updated: 2024/06/28 23:47:01 by tesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIL_DE_FER_H 
# define FIL_DE_FER_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include "libft/ft_printf.h"
# include "libft/get_next_line.h"

typedef struct s_cell
{
	int	z-buff;
	int	colour;
}	t_cell;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		map_width;
	int		map_height;
	char	***char_map;
	t_cell	**map;
}	t_data;

typedef struct s_point
{
	float x;
	float y;
	float z;
}	t_point;

typedef struct s_matrix
{
	float m[4][4];
}	t_matrix;

int		verify(int argc, const char *argv[], t_data	*data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	free_split(char **strs);

# endif
