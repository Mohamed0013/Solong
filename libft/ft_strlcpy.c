/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohdahma <mohdahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:03:27 by mohdahma          #+#    #+#             */
/*   Updated: 2025/01/30 11:03:28 by mohdahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_strlcpy(char *d, const char *s, size_t n)
{
	size_t	i;
	size_t	c;
	char	*p;

	p = (char *)s;
	c = 0;
	while (p[c] != '\0')
		c++;
	if (n != 0)
	{
		i = 0;
		while (i < (n - 1) && s[i] != '\0')
		{
			d[i] = s[i];
			i++;
		}
		d[i] = '\0';
	}
	return (c);
}
