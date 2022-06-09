/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karimvaliev <karimvaliev@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:30:01 by tyuuki            #+#    #+#             */
/*   Updated: 2021/10/20 15:06:06 by karimvaliev      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*prov(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (ft_strlen(s) <= start || len == 0)
	{
		str = (char *) malloc(1);
		*str = '\0';
		return (str);
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	k;

	i = 0;
	k = 0;
	str = prov(s, start, len);
	if (str)
		return (str);
	if (!len && !start)
		return (ft_strdup(s));
	if (len >= ft_strlen(s))
		return (ft_strdup(&s[start]));
	str = (char *) malloc(len + 1);
	if (str == NULL)
		return (NULL);
	while (i <= len - 1 && s[i])
	{
		str[k] = s[start + i];
		k++;
		i++;
	}
	str[k] = '\0';
	return (str);
}
