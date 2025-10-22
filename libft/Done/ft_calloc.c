/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oused-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 19:52:11 by oused-da          #+#    #+#             */
/*   Updated: 2025/10/22 20:26:31 by oused-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;
	size_t	i;

	if (nmemb && size && nmemb > SIZE_MAX / size)
		return (NULL);
	i = nmemb * size;
	s = (void *)malloc(i);
	if (!s)
		return (NULL);
	ft_bzero(s, i);
	return (s);
}
