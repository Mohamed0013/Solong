/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerrakc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:34:11 by smerrakc          #+#    #+#             */
/*   Updated: 2022/11/06 10:44:20 by smerrakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strchr( const char *str, int c)
{
	int		i;
	char	*p;

	i = 0;
	p = (char *)str;
	while (p[i] != '\0' && p[i] != (char)c)
		i++;
	if (p[i] == (char)c)
		return (p + i);
	return (0);
}
