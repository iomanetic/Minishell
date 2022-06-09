/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:29:58 by tyuuki            #+#    #+#             */
/*   Updated: 2021/10/11 15:23:39 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s_1_ptr;
	unsigned char	*s_2_ptr;
	int				i;

	s_1_ptr = (unsigned char *)s1;
	s_2_ptr = (unsigned char *)s2;
	i = 0;
	while (i < (int)n)
	{
		if (*s_1_ptr != *s_2_ptr)
			return (*s_1_ptr - *s_2_ptr);
		s_1_ptr++;
		s_2_ptr++;
		i++;
	}
	return (0);
}
