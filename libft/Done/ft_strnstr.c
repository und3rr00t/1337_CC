/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oused-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:52:32 by oused-da          #+#    #+#             */
/*   Updated: 2025/10/17 17:09:58 by oused-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		if (little[j] && little[j] == big[i])
		{
			while (little[j] && little[j] == big[i])
			{
				i++;
				j++;
			}

		}
		else
			i++;
	}
	return (NULL);
}
