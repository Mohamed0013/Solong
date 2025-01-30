/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohdahma <mohdahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:04:19 by mohdahma          #+#    #+#             */
/*   Updated: 2025/01/30 11:04:20 by mohdahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_lennbr(int i)
{
	if (i < 0)
		return (ft_lennbr(-i) + 1);
	if (i > 9)
		return (ft_lennbr(i / 10) + 1);
	return (1);
}

char	*ft_itoa(int nb)
{
	int		len;
	char	*s;

	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_lennbr(nb);
	s = malloc(sizeof(char) * len + 1);
	if (!s)
		return (NULL);
	if (nb == 0)
		s[0] = '0';
	if (nb < 0)
	{
		s[0] = '-';
		nb = -nb;
	}
	s[len--] = '\0';
	while (len >= 0 && nb > 0)
	{
		s[len--] = '0' + (nb % 10);
		nb = nb / 10;
	}
	return (s);
}
