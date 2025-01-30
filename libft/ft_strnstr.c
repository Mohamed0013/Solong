/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohdahma <mohdahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:02:35 by mohdahma          #+#    #+#             */
/*   Updated: 2025/01/30 11:02:36 by mohdahma         ###   ########.fr       */
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
