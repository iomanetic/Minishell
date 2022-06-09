/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:30:13 by tyuuki            #+#    #+#             */
/*   Updated: 2021/10/08 17:30:14 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *destination, int c, unsigned int n)
{
	char	*buf;

	buf = destination;
	while (n > 0)
	{
		*buf = c;
		buf++;
		n--;
	}
	return (destination);
}
