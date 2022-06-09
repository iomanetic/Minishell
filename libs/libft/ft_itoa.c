/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karimvaliev <karimvaliev@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:30:36 by tyuuki            #+#    #+#             */
/*   Updated: 2021/10/20 13:50:45 by karimvaliev      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	value(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static	int	len_int(long int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*output;
	int		i;

	i = len_int(n);
	output = (char *)malloc (sizeof(char) * len_int(n) + 1);
	if (output == NULL)
		return (NULL);
	output[i] = '\0';
	if (n < 0)
		output[0] = '-';
	if (n == 0)
	{
		output[0] = '0';
		output[1] = '\0';
	}
	while (n != 0)
	{
		i--;
		output[i] = value(n % 10) + '0';
		n /= 10;
	}
	return (output);
}
