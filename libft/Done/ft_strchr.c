/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oused-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 22:16:31 by oused-da          #+#    #+#             */
/*   Updated: 2025/10/16 22:28:57 by oused-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
char	*ft_strchr(const char *s, int c)
{
	int	i;
	char	*ss;

	ss = (char)s;
	i = 0;
	while (1)
	{
		if (ss[i] == c)
			return (&ss[i]);
		if (ss[i] == '\0')
			return (NULL);
		i++;
	}
	return (NULL);
}
