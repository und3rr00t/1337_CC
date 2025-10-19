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
void ft_putnbr(long int nb, int *j)
{
	if (nb < 0)
	{
		nb = -nb;
		**s = '-';
		(*s)++;
	}
	if (nb > 9)
		ft_putnbr((nb / 10), s);
	**s = (nb % 10) + 48;
	(*s)++;
}


char	*ft_itoa(int n)
{
	char	*s;
	int	i;
	long int	l;
	long int	nb;
	int	j;

	nb = n;
	i = 0;
	if (n == 0)
	{
		s = (char *)malloc(sizeof(char) * 2);
		if (!s)
			return (NULL);
		s[0] = 48;
		s[1] = 0;
		return (s);
	}
	if (n < 0)
	{
		nb = -nb;
		i++;
	}
	l = nb;
	while (l)
	{
		l = l / 10;
		i++;
	}
	s = (char *)malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	if (n < 0)
		nb = -nb;
	ft_putnbr(nb, s);
	return (s);
}
int main()
{
	printf("%s\n", ft_itoa(1000));
}
	
