/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:29:53 by tyuuki            #+#    #+#             */
/*   Updated: 2021/10/11 13:00:30 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*s_ptr;

	s_ptr = s;
	while (n > 0)
	{
		if (*s_ptr == (unsigned char)c)
			return ((void *)s_ptr);
		s_ptr++;
		n--;
	}
	return (NULL);
}
