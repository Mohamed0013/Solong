/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerrakc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 10:44:58 by smerrakc          #+#    #+#             */
/*   Updated: 2022/11/06 12:07:55 by smerrakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		j;
	char	*p;
	char	*p1;

	i = 0;
	p = (char *)s1;
	p1 = (char *)s2;
	if (*p1 == 0)
		return (p);
	if (n == 0)
		return (NULL);
	while (p[i] != '\0')
	{
		j = 0;
		while (p[i + j] == p1[j] && p[i + j] != '\0' && i + j < n)
		{
			if (p1[j + 1] == '\0')
				return (p + i);
			j++;
		}
		i++;
	}
	return (0);
}
