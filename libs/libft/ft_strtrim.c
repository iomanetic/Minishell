/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:32:15 by tyuuki            #+#    #+#             */
/*   Updated: 2021/10/19 21:24:33 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	beg;
	size_t	end;
	size_t	i;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1);
	beg = 0;
	while (ft_strchr(set, s1[beg]) && s1[beg])
		beg++;
	while (ft_strchr(set, s1[end - 1]) && end > beg)
		end--;
	str = (char *) malloc(sizeof(char) * (end - beg + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (beg < end)
		str[i++] = s1[beg++];
	str[i] = '\0';
	return (str);
}
