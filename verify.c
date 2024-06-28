//
//  verify.c
//  fil_de_fer
//
//  Created by Teghjyot Singh on 27/6/2024.
//

#include "fil_de_fer.h"

void free_split(char **strs)
{
	size_t	i;

	if (strs == NULL)
		return;
	i = 0;
	while (strs[i] != NULL)
		free(strs[i++]);
	free(strs);
}

int	check_map(const char *filepath, int fd, t_data *data)
{
	char	*line;
	char	**fmt_line;
	int		map_x;
	int		temp_x;

	line = get_next_line(fd);
	fmt_line = ft_split(line, ' ');
	map_x = 0;
	data->map_height = 0;
	while (strncmp(fmt_line[map_x], "\n", 1) && fmt_line[++map_x])
		continue;
	temp_x = 0;
	while (line)
	{
		while (strncmp(fmt_line[temp_x], "\n", 1) && fmt_line[++temp_x])
			continue;
		if (temp_x != map_x)
			return (1);
		else
			temp_x = 0;
		free(line);
		line = get_next_line(fd);
		data->map_height++;
	}
	free_split(fmt_line);
	free(line);
	data->map_width = map_x;
	return (0);
}

int	verify(int argc, const char *argv[], t_data	*data)
{
	char	*file_extension;
	int		fd;
	int		ret;

	if (argc != 2 || ft_strlen(argv[1]) < 5)
	{
		ft_printf("usage: ./fdf <filename>.fdf\n");
		return (1);
	}
	ret = 0;
	file_extension = ft_substr(argv[1], (u_int)(ft_strlen(argv[1]) - 4), ft_strlen(argv[1]));
	if (ft_strncmp(file_extension, ".fdf", 4))
	{
		free(file_extension);
		return (1);
	}
	free(file_extension);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("%s does not exist\n", argv[1]);
		return (1);
	}
	if (check_map(argv[1], fd, data))
		ret = 1;
	close(fd);
	return (ret);
}
