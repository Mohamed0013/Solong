/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohdahma <mohdahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:04:35 by mohdahma          #+#    #+#             */
/*   Updated: 2025/01/24 15:18:17 by mohdahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <ctype.h>
# include <unistd.h>
# include <fcntl.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct a_data
{
	char	**p;
	int		y;
	int		x;
	int		nb_c;
	int		e_x;
	int		length;
	int		nb_lines;
}t_data;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int		x;
	int		y;
	int		nb_m;
	int		nc;
	char	**s;
	void	*img_p1;
	void	*img_p2;
	void	*img_p3;
	void	*img_p4;
	void	*img_p5;

}t_game;

void	ft_alloc_map2(t_game *game, char **map);
void	save_position(t_game *game, char **map);
void	ft_check_walls(char **map);
void	ft_check_walls2(char **map);
void	perror_fct(char *s);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_getfilecontent(int fd);
char	*ft_strchr( const char *str, int c);
char	**reading_map(int fd);
size_t	ft_strlen(const char *str);
int		map_caracter(char **map, char c);
void	cheaking_map(char **map);
void	save_pos(t_data *data, char **map);
void	alloc_map(t_data *data, char **map);
void	mlx_path_image(t_game *game);
void	put_to_window(t_game *game, char **map, int x, int y);
void	func_move(int keycode, int x, int y, t_game *game);
char	*ft_itoa(int n);
int		collec_check(t_game *game);
void	path_is_valid(char	**map, int status);
int		nb_collec(char **map);
void	cheaking_path(t_data *data, int y, int x, int i);
char	**ft_free(char **s);
void	check_extension(char *av, char *ext);
int		keyhook(int keycode, t_game *game);
void	ft_free2(t_data *data);
int		func_hook(void);
void	ft_is_newline(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *src);
void	check_xpm(void *s);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *s, int c, size_t n);
void	rendring_game(char **map);

#endif