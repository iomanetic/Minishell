/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:30:47 by tyuuki            #+#    #+#             */
/*   Updated: 2021/10/08 17:30:47 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*str;

	str = NULL;
	while (*s)
	{
		if (*s == (char)c)
			str = s;
		s++;
	}
	if (*s == (char)c)
		str = s;
	return ((char *)str);
}
