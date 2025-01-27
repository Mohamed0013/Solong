/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohdahma <mohdahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:03:59 by mohdahma          #+#    #+#             */
/*   Updated: 2025/01/23 13:04:00 by mohdahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keyhook(int keycode, t_game *game)
{
	printf("Enterd !!");
	if (keycode == 65307)
		exit(0);
	if (keycode == 65362 || keycode == 119)
		func_move(keycode, game->x, game->y - 1, game);
	else if (keycode == 65364 || keycode == 115)
		func_move(keycode, game->x, game->y + 1, game);
	else if (keycode == 100 || keycode == 65363)
		func_move(keycode, game->x + 1, game->y, game);
	else if (keycode == 97 || keycode == 65361)
		func_move(keycode, game->x - 1, game->y, game);
	return (0);
}

int	collec_check(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (game->s[i] != NULL)
	{
		j = 0;
		while (game->s[i][j])
		{
			if (game->s[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
}

void	ft_print_mov(t_game *game)
{
	char	*c;

	c = ft_itoa(game->nb_m);
	write(1, "move = ", 7);
	ft_putstr(c);
	write (1, "\n", 1);
	free(c);
}

void	func_move(int keycode, int x, int y, t_game *game)
{
	game->nc = collec_check(game);
	if (game->s[y][x] == '0' || game->s[y][x] == 'C')
	{
		if (game->s[y][x] == 'C')
			game->nc--;
		if (keycode == 65364 || keycode == 115)
			game->s[y - 1][x] = '0';
		else if (keycode == 65362 || keycode == 119)
			game->s[y + 1][x] = '0';
		else if (keycode == 65361 || keycode == 97)
		{
			game->s[y][x + 1] = '0';
		}
		else if (keycode == 65363 || keycode == 100)
			game->s[y][x - 1] = '0';
		game->s[y][x] = 'P';
		game->x = x;
		game->y = y;
		game->nc++;
		game->nb_m++;
		put_to_window(game, game->s, 0, 0);
		ft_print_mov(game);
	}
	else if (game->s[y][x] == 'E' && game->nc == 0)
		exit(EXIT_SUCCESS);
}
