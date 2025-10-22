/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oused-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:00:41 by oused-da          #+#    #+#             */
/*   Updated: 2025/10/22 16:56:28 by oused-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*include "libft.h"*/

int	ft_substr(char *s, char c)
{
	int	i;
	int	sub;

	i = 0;
	sub = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			sub++;
		}
		i++;
	}
	return (sub);
}

int	ft_sep(char *s, char c, int *i)
{
	int	j;

	j = 0;
	while (s[*i] != c)
	{
		(*i)++;
		j++;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int	i;
	ret = (char **)malloc(sizeof(char *) * (ft_substr(s, c) + 1));
	if (!ret)
		return (NULL);


#include <stdio.h>
int main(int c, char **v)
{
	if ( c != 3)
		return 0;
	printf("%d\n", ft_substr(v[1], v[2][0]));
}
