/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerrakc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 16:37:33 by smerrakc          #+#    #+#             */
/*   Updated: 2022/11/06 10:55:26 by smerrakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_strlcat(char *d, const char *s, size_t n)
{
	size_t	ld;
	size_t	ls;
	size_t	k;
	size_t	a;

	ld = ft_strlen(d);
	ls = ft_strlen(s);
	if (!d && n == 0)
		return (ls);
	a = ld;
	k = 0;
	if (n <= ld)
		return (ls + n);
	if (n > ld)
	{
		while (s[k] != '\0' && ld < n - 1)
			d[ld++] = s[k++];
		d[ld] = '\0';
	}
	return (a + ls);
}
