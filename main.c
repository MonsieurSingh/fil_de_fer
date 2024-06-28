/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tesingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 22:53:57 by tesingh           #+#    #+#             */
/*   Updated: 2024/06/29 06:50:09 by tesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fil_de_fer.h"

int	create_cell(t_cell *cell, t_data *data, int fd)
{
	int		k;
	char	*line;
	char	*temp;
	char	**fmt;

	k = 0;
	while(k < data->map_height)
	{
		line = get_next_line(int fd);
		fmt = ft_split(line, ',');
		temp = ft_trim(fmt[0], " \t\n\v\b");
		cell->z-buff = ft_atoi(temp);
		free(temp);
		if (fmt[1])
		{
			temp = ft_trim(fmt[1], " \t\n\v\b");
			cell->colour = ft_atoi_base(temp);
			free(temp);
		}
		cell->colour = ft_
		ft_striteri();
		free(line);
		k++;
	}
	free_split(fmt);
	return (0);
}

int	create_map(const char *argv[], t_data *data)
{
	int		fd;
	int		i;
	int		j;
	t_cell	cell;

	data->map = (t_cell **)malloc(data->map_height);
	if (!data->map)
		return (1);
	ft_bzero(&cell, sizeof(t_cell));
	i = 0;
	fd = open(argv[1], O_RDONLY);
	while (i < data->map_height)
	{
		data->map[i] = (t_cell *)malloc(data->map_width);
		j = 0;
		while(j < data-map_width)
		{
			create_cell(&cell, data, fd);
			j++;
		}
		i++;
	}
	close(fd);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(int argc, const char *argv[])
{
	t_data	data;
	int		ret;

	ret = 0;
	if (verify(argc, argv, &data))
		ret = 1;
	return (ret);
}
