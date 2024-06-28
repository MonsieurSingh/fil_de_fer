//
//  main.c
//  fil_de_fer
//
//  Created by Teghjyot Singh on 25/6/2024.
//

#include "fil_de_fer.h"

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
