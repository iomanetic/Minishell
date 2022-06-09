/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:30:42 by tyuuki            #+#    #+#             */
/*   Updated: 2021/10/11 16:14:32 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;

	i = 0;
	if (!(*little))
		return ((char *)big);
	if (ft_strlen(big) < ft_strlen(little))
		return (NULL);
	while (little[i] && (unsigned long)i < len && big[i])
	{
		if (big[i] != little[i])
		{
			big++;
			i = -1;
			len--;
		}
		i++;
	}
	if (!little[i])
		return ((char *)big);
	return (NULL);
}
