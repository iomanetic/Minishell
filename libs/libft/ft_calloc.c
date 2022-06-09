/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karimvaliev <karimvaliev@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:43:26 by tyuuki            #+#    #+#             */
/*   Updated: 2021/10/20 14:47:56 by karimvaliev      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*mass;
	int		i;

	i = 0;
	mass = (void *) malloc(nmemb * size);
	if (mass == NULL)
		return (NULL);
	while (i < (int)nmemb * (int)size)
	{
		mass[i] = '\0';
		i++;
	}
	return ((void *)mass);
}
