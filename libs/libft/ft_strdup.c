/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:06:59 by tyuuki            #+#    #+#             */
/*   Updated: 2021/10/19 14:18:24 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s_2;
	size_t	len_s;
	size_t	i;

	len_s = ft_strlen(s);
	i = 0;
	s_2 = (void *) malloc(sizeof(void) * len_s + 1);
	if (s_2 == NULL)
		return (NULL);
	while (i < len_s)
	{
		s_2[i] = s[i];
		i++;
	}
	s_2[i] = '\0';
	return (s_2);
}
