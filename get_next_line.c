/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohdahma <mohdahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:18:35 by mohdahma          #+#    #+#             */
/*   Updated: 2025/01/31 18:18:04 by mohdahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_is_newline(char *s)
{
	int	i;

	i = 0;
	if (s[0] == '\n')
		perror_fct("error; newline in beggining of map\n");
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
		perror_fct ("error; newline in the end of map\n");
}

char	*ft_getfilecontent(int fd)
{
	char	*buffer;
	char	*s;
	char	*holder;
	ssize_t	n;

	s = NULL;
	n = 1;
	buffer = malloc(5 * sizeof(char) + 1);
	if (!buffer)
		return (NULL);
	while (n > 0)
	{
		n = read(fd, buffer, 5);
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
