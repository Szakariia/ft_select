/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-mab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 09:16:45 by zael-mab          #+#    #+#             */
/*   Updated: 2019/04/19 03:23:34 by zael-mab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_x(int nb)
{
	size_t	j;

	j = 1;
	while (nb / 10)
	{
		nb = nb / 10;
		j++;
	}
	return (j);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		y;
	int		z;
	long	nb;

	nb = n;
	y = ft_x(n);
	z = (n < 0 ? 1 : 0);
	if (!(str = ft_strnew(y + z)))
		return (NULL);
	if (z)
	{
		nb = (int long)n * -1;
		str[0] = '-';
	}
	while (y > 0)
	{
		str[y + z - 1] = nb % 10 + 48;
		nb = nb / 10;
		y--;
	}
	return (str);
}
