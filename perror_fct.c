/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perror_fct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohdahma <mohdahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:17:55 by mohdahma          #+#    #+#             */
/*   Updated: 2025/01/30 10:17:56 by mohdahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s != '\0')
	{
		write(fd, s, 1);
		s++;
	}
}

void	perror_fct(char *s)
{
	ft_putstr_fd(s, 2);
	exit(1);
}

void	check_xpm(void *s)
{
	if (!s)
		perror_fct("cannot open file xpm try again !!\n");
}
