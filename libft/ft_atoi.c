/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oused-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:11:02 by oused-da          #+#    #+#             */
/*   Updated: 2025/10/27 16:45:50 by oused-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	check_overf(const char *nptr, int s)
{
	long int	o;
	int			n;

	o = 0;
	while (ft_isdigit(*nptr))
	{
		n = *nptr - 48;
		if (o > (LONG_MAX - n) / 10 && s == 1)
			return (-1);
		else if (o > (LONG_MAX - n) / 10 && s == -1)
			return (0);
		o = o * 10 + n;
		nptr++;
	}
	return (o * s);
}

int	ft_atoi(const char *nptr)
{
	size_t		i;
	long int	s;

	i = 0;
	s = 1;
	while ((nptr[i] == 32) || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s *= -1;
		i++;
	}
	return ((int)check_overf(&nptr[i], s));
}
