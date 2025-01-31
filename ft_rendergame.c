/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rendergame.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohdahma <mohdahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:04:59 by mohdahma          #+#    #+#             */
/*   Updated: 2025/01/30 15:51:17 by mohdahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void apply_transparency(void *img, int width, int height)
// {
//     int bpp, size_line, endian;
//     char *data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
//     int x, y;
//     int color;

//     for (y = 0; y < height; y++)
//     {
//         for (x = 0; x < width; x++)
//         {
//             int index = (y * size_line) + (x * (bpp / 8));
//             color = *(int *)(data + index);

//             if (color == 0x000000) // If black
//     			*(int *)(data + index) = 0xFF000000; // Make it transparent
//         }
//     }
// }

void	ft_alloc_map2(t_game *game, char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
		i++;
	game->cont = malloc((i + 1) * sizeof(char *));
	i = 0;
	while (map && map[i])
	{
		game->cont[i] = ft_strdup(map[i]);
		i++;
	}
	game->cont[i] = NULL;
}

void	save_position(t_game *game, char **map)
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
				game->x = j;
				game->y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	mlx_path_image(t_game *game)
{
	int	x;
	int	y;

	game->img_p1 = mlx_xpm_file_to_image(game->mlx,
			"./image/wall.xpm", &x, &y);
	check_xpm(game->img_p1);
	game->img_p2 = mlx_xpm_file_to_image(game->mlx,
			"./image/rows.xpm", &x, &y);
	check_xpm(game->img_p2);
	game->img_p3 = mlx_xpm_file_to_image(game->mlx,
			"./image/player.xpm", &x, &y);
	check_xpm(game->img_p3);
	// apply_transparency(game->img_p3, x, y);
	game->img_p4 = mlx_xpm_file_to_image(game->mlx,
			"./image/collectif.xpm", &x, &y);
	check_xpm(game->img_p4);
	game->img_p5 = mlx_xpm_file_to_image(game->mlx,
			"./image/exit.xpm", &x, &y);
	check_xpm(game->img_p5);
}

void	put_to_window(t_game *game, char **map, int x, int y)
{
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				mlx_put_image_to_window (game->mlx, game->mlx_win, game->img_p1,
					x * 50, y * 50);
			if (map[y][x] == '0')
				mlx_put_image_to_window (game->mlx, game->mlx_win, game->img_p2,
					x * 50, y * 50);
			if (map[y][x] == 'P'){
				mlx_put_image_to_window (game->mlx, game->mlx_win, game->img_p2,
					x * 50, y * 50);
				mlx_put_image_to_window (game->mlx, game->mlx_win, game->img_p3,
					x * 50, y * 50);
			}
			if (map[y][x] == 'C')
				mlx_put_image_to_window (game->mlx, game->mlx_win, game->img_p4,
					x * 50, y * 50);
			if (map[y][x] == 'E')
				mlx_put_image_to_window (game->mlx, game->mlx_win, game->img_p5,
					x * 50, y * 50);
			x++;
		}
		y++;
	}
}

void	rendring_game(char **map)
{
	t_game	game;
	int		i;
	int		j;

	j = 0;
	ft_alloc_map2(&game, map);
	save_position(&game, map);
	game.mlx = mlx_init();
	game.nb_move = 0;
	while (map && map[j])
		j++;
	i = ft_strlen(map[0]);
	game.mlx_win = mlx_new_window(game.mlx, i * 50, j * 50, "So_Long");
	mlx_path_image(&game);
	put_to_window(&game, map, 0, 0);
	mlx_hook(game.mlx_win, 17, 0, func_hook, NULL);
	mlx_key_hook(game.mlx_win, keyhook, &game);
	mlx_loop(game.mlx);
}
