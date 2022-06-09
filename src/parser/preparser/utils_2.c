/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:31:00 by tyuuki            #+#    #+#             */
/*   Updated: 2022/06/08 17:28:14 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_isdollar2(char c)
{
	if (c == '_' || ft_isalnum(c))
		return (TRUE);
	return (FALSE);
}

void	norm_help_dollar(char **str, int *j)
{
	while ((*str)[(*j)])
	{
		if ((*str)[(*j)] == '?')
		{
			(*j)++;
			break ;
		}
		(*j)++;
		if (!ft_isdollar2((*str)[(*j)]))
			break ;
	}
}
