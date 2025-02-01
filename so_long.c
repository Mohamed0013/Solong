/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohdahma <mohdahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:25:46 by mohdahma          #+#    #+#             */
/*   Updated: 2025/01/31 17:53:43 by mohdahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_extension(char *str, char *ext)
{
	size_t	i;
	int		j;
	int		point;

	i = ft_strlen(str);
	if (i <= 4)
		perror_fct("error :your map extention is not valid\n ");
	j = i - 4;
	i = 0;
	while (str[j] && ext[i])
		if (str[j++] != ext[i++])
			perror_fct("error :your map extention is not valid\n");
	j = 0;
	point = 0;
	while (str[j++])
		if (str[j] == '.')
			point++;
	if (point > 1)
		perror_fct("error :check the extention !\n");
}

int	main(int ac, char **av)
{
	char	**map;
	int		game_file;

	if (ac == 2)
	{
		game_file = open(av[1], O_RDONLY);
		if (!game_file)
			perror_fct("arguments not valid\n");
		check_extension(av[1], ".ber");
		map = reading_map(game_file);
		cheaking_map(map);
		path_is_valid(map, 0);
		path_is_valid(map, 1);
		rendring_game(map);
		ft_free(map);
	}
	else
		perror_fct ("arguments not valid\n");
}
