/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerrakc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 20:10:54 by smerrakc          #+#    #+#             */
/*   Updated: 2023/01/07 20:11:13 by smerrakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_is_newline(char *s)
{
	int	i;

	i = 0;
	if (s[0] == '\n')
		perror_fct("error; newline in map\n");
	while (s[i])
	{
		if (s[i] == '\n')
		{
			if (s[i + 1] == '\n')
				perror_fct("error : newline in map\n");
		}
		i++;
	}
	if (s[i - 1] == '\n')
		perror_fct ("error; map invalid");
}

char	*ft_getfilecontent(int fd)
{
	char	*buffer;
	char	*s;
	char	*holder;
	ssize_t	n;

	s = NULL;
	buffer = malloc(5 * sizeof(char) + 1);
	if (!buffer)
		return (NULL);
	while ((n = read(fd, buffer, 5)))
	{
		if (n <= 0)
			break ;
		buffer[n] = '\0';
		holder = s;
		s = ft_strjoin(s, buffer);
		free(holder);
	}
	free (buffer);
	return (s);
}

char	**reading_map(int fd)
{
	char	**map;
	char	*content;

	content = ft_getfilecontent(fd);
	if (ft_strlen(content) == 0)
		perror_fct ("map not valid\n");
	ft_is_newline(content);
	map = ft_split(content, '\n');
	free(content);
	return (map);
}
