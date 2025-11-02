/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oused-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 19:18:51 by oused-da          #+#    #+#             */
/*   Updated: 2025/10/25 16:50:19 by oused-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr(long int nb, char *s, int *i)
{
	if (nb < 0)
	{
		s[(*i)++] = '-';
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr((nb / 10), s, i);
	s[(*i)++] = (nb % 10) + 48;
}

char	*ft_itoa(int n)
{
	char	*s;
	long	nb;
	int		l;
	int		tmp;
	int		i;

	nb = n;
	l = (n <= 0);
	tmp = n;
	i = 0;
	while (tmp)
	{
		tmp /= 10;
		l++;
	}
	s = malloc(l + 1);
	if (!s)
		return (NULL);
	if (n == 0)
		s[i++] = 48;
	else
		ft_putnbr(nb, s, &i);
	s[i] = 0;
	return (s);
}
