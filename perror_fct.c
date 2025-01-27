/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perror_fct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerrakc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:37:46 by smerrakc          #+#    #+#             */
/*   Updated: 2023/09/18 12:37:51 by smerrakc         ###   ########.fr       */
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
