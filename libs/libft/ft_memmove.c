/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karimvaliev <karimvaliev@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:30:07 by tyuuki            #+#    #+#             */
/*   Updated: 2021/10/20 14:30:44 by karimvaliev      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void *src, unsigned int n)
{
	unsigned char	*temp;
	unsigned char	*temp_2;
	unsigned int	i;

	temp_2 = dest;
	temp = src;
	i = 0;
	if (src == dest || n == 0)
		return (dest);
	if (dest > src)
	{
		while (n--)
			temp_2[n] = temp[n];
		return (dest);
	}
	while (i < n)
	{
		temp_2[i] = temp[i];
		i++;
	}
	return (dest);
}
