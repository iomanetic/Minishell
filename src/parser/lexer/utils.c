/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:31:00 by tyuuki            #+#    #+#             */
/*   Updated: 2021/10/19 14:31:05 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/minishell.h"

int	push_token(t_minishell *shell, int key_t, char *value)
{
	ft_lstadd_back(&shell->token, ft_lstnew((void *)0, (char *)value, key_t));
	return (FALSE);
}

int	ft_isdollar(char c)
{
	if (c == '_' || ft_isalnum(c) || c == '?')
		return (TRUE);
	return (FALSE);
}

int	ft_isvalid(char c)
{
	if (c == '>' || c == '<' || c == '|' || c == ' ' \
	|| c == '\'' || c == '\"' || c == '$' || c == '\\' || c == ';')
		return (0);
	return (1);
}
