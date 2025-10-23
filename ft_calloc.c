/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oused-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 19:52:11 by oused-da          #+#    #+#             */
/*   Updated: 2025/10/23 13:32:52 by oused-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;
	size_t	i;

	if (nmemb > SIZE_MAX / size)
		return (NULL);
	i = nmemb * size;
	if (i == 0)
	{
		s = (void *)malloc(1);
		if (!s)
			return (NULL);
		return (s);
	}
	s = (void *)malloc(i);
	if (!s)
		return (NULL);
	ft_bzero(s, i);
	return (s);
}
