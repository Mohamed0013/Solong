/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohdahma <mohdahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:05:09 by mohdahma          #+#    #+#             */
/*   Updated: 2025/01/30 11:01:18 by mohdahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	alloc_map(t_data *data, char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
		i++;
	data->p = malloc((i + 1) * sizeof(char *));
	if (!data->p)
	{
		perror("Error allocating memory for data->p");
		return ;
	}
	data->nb_lines = i;
	i = 0;
	while (map && map[i])
	{
		data->p[i] = ft_strdup(map[i]);
		i++;
	}
	data->p[i] = NULL;
}

void	save_pos(t_data *data, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map && map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				data->x = j;
				data->y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	cheaking_path(t_data *data, int y, int x, int i)
{
	if (y < 0 || y >= data->nb_lines || x < 0 || x >= data->length
		|| data->p[y][x] == '1')
		return ;
	if (data->p[y][x] == 'E' && i == 0 && data->nb_c > 0)
		return ;
	if (i == 0)
	{
		if (data->p[y][x] == 'C')
			data->nb_c--;
	}
	else
	{
		if (data->p[y][x] == 'E')
			data->e_x = 0;
	}
	data->p[y][x] = '1';
	cheaking_path(data, y, x + 1, i);
	cheaking_path(data, y + 1, x, i);
	cheaking_path(data, y, x - 1, i);
	cheaking_path(data, y - 1, x, i);
}

void	path_is_valid(char **map, int status)
{
	t_data	data;
	int		i;

	data.nb_c = nb_collec(map, &data);
	data.e_x = 1;
	data.length = ft_strlen(map[0]);
	if (data.length >= 327 || data.nb_lines >= 327)
		perror_fct("Error: Map very large\n");
	save_pos(&data, map);
	alloc_map(&data, map);
	cheaking_path(&data, data.y, data.x, status);
	if ((status == 1 && data.e_x == 0) || (status == 0 && data.nb_c == 0))
	{
		ft_free2(&data);
		return ;
	}
	ft_free2(&data);
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	perror_fct("Error: Path is not valid\n");
}
