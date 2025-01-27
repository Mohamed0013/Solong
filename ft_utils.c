/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohdahma <mohdahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:04:43 by mohdahma          #+#    #+#             */
/*   Updated: 2025/01/24 15:42:50 by mohdahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	nb_collec(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map && map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	ft_free2(t_data *data)
{
	int		i;

	i = 0;
	while (data->p[i]) // Free each row in the 2D map
	{
		free(data->p[i]);
		i++;
	}
	free(data->p); // Free the array of pointers
}

int	func_hook(void)
{
	exit (1);
	return (0);
}
