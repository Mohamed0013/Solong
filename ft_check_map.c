/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohdahma <mohdahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:05:23 by mohdahma          #+#    #+#             */
/*   Updated: 2025/01/31 18:33:15 by mohdahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_caracter(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			if (!ft_strchr("01ECP", map[i][j]))
				perror_fct("error: Check the caracters in map\n");
			j++;
		}
		i++;
	}
	return (count);
}

void	ft_check_walls(char **map)
{
	int	j;

	j = 0;
	while (map[0][j] != '\0')
	{
		if (map[0][j] != '1')
			perror_fct ("Error: no wall in the start\n");
		j++;
	}
	ft_check_walls2(map);
}

void	ft_check_walls2(char **map)
{
	int	i;
	int	j;

	i = 1;
	j = ft_strlen(map[i]) - 1;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][j] != '1')
			perror_fct ("Error: should be a wall here \n");
		i++;
	}
	i--;
	while (j >= 0)
	{
		if (map[i][j] != '1')
			perror_fct ("Error: should be a wall here\n");
		j--;
	}
}

void	cheaking_map(char **map)
{
	int	i;

	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
			perror_fct("error: map not valid\n");
		i++;
	}
	ft_check_walls(map);
	if (map_caracter(map, 'C') < 1 || map_caracter(map, 'P') != 1)
		perror_fct("error : Ivalid Caracters\n");
	if (map_caracter(map, 'E') != 1)
		perror_fct("error : caracter \"EXIT\" not valid\n" );
}
