/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:30:03 by tyuuki            #+#    #+#             */
/*   Updated: 2021/10/19 14:14:32 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, unsigned int n)
{
	unsigned const char	*temp;
	unsigned char		*temp_2;

	temp_2 = dest;
	temp = src;
	if (!dest && !src)
		return (NULL);
	while (n > 0)
	{
		*temp_2 = *temp;
		temp_2++;
		temp++;
		n--;
	}
	return (dest);
}
