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

int	search_tokens(t_minishell *shell, int *i)
{
	if (shell->line[*i] && ft_isspace(shell->line[*i]))
		return (push_token(shell, SEP, ft_strdup(" ")));
	else if (shell->line[*i] == '\'')
		return (search_quetos(shell, i, '\'', SING_QUO));
	else if (shell->line[*i] == '\"')
		return (search_quetos(shell, i, '\"', DOUB_QUO));
	else if (shell->line[*i] == '|')
		return (push_token(shell, PIPE, ft_strdup("")));
	else if (shell->line[*i] == '\\')
		return (ft_error(E_US, "\\"));
	else if (shell->line[*i] == ';')
		return (ft_error(E_US, ";"));
	else if (shell->line[*i] == '$')
		return (get_dollar(shell, i, DOLLAR));
	else if (!redirects(shell, i))
		return (FALSE);
	else
		return (get_word(shell, i, WORD));
}

int	lexer(t_minishell *shell)
{
	int	i;

	i = 0;
	while (shell->line[i])
	{
		if (search_tokens(shell, &i))
			return (TRUE);
		i++;
	}
	return (FALSE);
}
