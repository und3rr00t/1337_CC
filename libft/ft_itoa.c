/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oused-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 19:18:51 by oused-da          #+#    #+#             */
/*   Updated: 2025/10/19 22:08:57 by oused-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
void	ft_putnbr(long int nb, char *s,  int *i)
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
	int	i;
	long int	l;
	long int	nb;
	int	tmp;

	nb = n;
	if (n == 0)
	{
		s = (char *)malloc(sizeof(char) * 2);
		if (!s)
			return (NULL);
		s[0] = 48;
		s[1] = 0;
		return (s);
	}
	tmp = nb;
	if (tmp < 0)
		tmp = -tmp;
	l = 0;
	while (tmp)
	{
		tmp = tmp / 10;
		l++;
	}
	s = (char *)malloc(sizeof(char) * (l + 1));
	if (!s)
		return (NULL);
	i = 0;
	ft_putnbr(nb, s, &i);
	s[i] = 0;
	return (s);
}
