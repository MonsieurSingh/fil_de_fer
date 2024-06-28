/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tesingh <tesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 22:53:48 by tesingh           #+#    #+#             */
/*   Updated: 2024/06/29 06:49:21 by tesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	str_len(char *str)
{
	long	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static long	has_dupes(char *str)
{
	long	i;
	long	j;
	long	len;

	len = str_len(str);
	i = 0;
	while (i < len - 1)
	{
		if (str[i] == '+' || str[i] == '-')
			return (1);
		j = i + 1;
		while (j < len)
		{
			if (str[i] == str[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static long	char_index(char *base, char c)
{
	long	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static long	check_sign(char *str)
{
	long	sign;
	long	index;

	sign = 1;
	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '-')
			sign *= -1;
		else if (str[index] == '+')
			sign *= 1;
		index++;
	}
	return (sign);
}

int	ft_atoi_base(char *str, char *base)
{
	long			index;
	long			is_pos;
	long			nb;
	long			base_len;

	index = 0;
	is_pos = check_sign(str);
	nb = 0;
	base_len = str_len(base);
	if (base_len < 2 || has_dupes(base))
		return (0);
	while (str[index] != '\0')
	{
		if (str[index] != ' ' && str[index] != '+' && str[index] != '-'
			&& char_index(base, str[index]) != -1)
		{
			if (str[index - 1] == ' ')
				return (0);
			else
				nb = (base_len * nb) + char_index(base, str[index]);
		}
		index++;
	}
	return (is_pos * nb);
}
