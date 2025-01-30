/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohdahma <mohdahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:04:00 by mohdahma          #+#    #+#             */
/*   Updated: 2025/01/30 11:04:01 by mohdahma         ###   ########.fr       */
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
