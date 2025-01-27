/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohdahma <mohdahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 10:52:57 by smerrakc          #+#    #+#             */
/*   Updated: 2025/01/23 13:57:18 by mohdahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	*ft_sub(char const *s, unsigned int start, size_t len, char *p)
{
	unsigned int	i;
	size_t			j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (i >= start && j < len)
		{
			p[j] = s[i];
			j++;
		}
		i++;
	}
	p[j] = '\0';
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	char	*ptr;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	else
	{
		if (len > ft_strlen(s))
			len = ft_strlen(s) - start;
		if (len >= ft_strlen(&s[start]))
			len = ft_strlen(&s[start]);
		p = malloc(sizeof(char) * (len + 1));
		if (!p)
			return (NULL);
		ptr = ft_sub(s, start, len, p);
	}
	return (ptr);
}
