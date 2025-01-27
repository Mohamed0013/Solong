/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerrakc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 23:31:19 by smerrakc          #+#    #+#             */
/*   Updated: 2022/11/06 10:11:44 by smerrakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_lentnbr(int i)
{
	int	c;

	c = 0;
	if (i <= 0)
	{
		c = c + 1;
	}
	while (i != 0)
	{
		i = i / 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(int nb)
{
	long int	len;
	char		*s;

	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_lentnbr(nb);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	if (nb == 0)
		s[0] = '0';
	if (nb < 0)
	{
		s[0] = '-';
		nb = nb * (-1);
	}
	s[len--] = '\0';
	while (len >= 0 && nb > 0)
	{
		s[len--] = '0' + (nb % 10);
		nb = nb / 10;
	}
	return (s);
}
