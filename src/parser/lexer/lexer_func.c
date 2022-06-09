/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:31:00 by tyuuki            #+#    #+#             */
/*   Updated: 2022/06/08 16:52:43 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	search_quetos(t_minishell *shell, int *i, char type, int key_t)
{
	int		j;
	char	*tmp;

	j = *i + 1;
	while (shell->line[j] && shell->line[j] != type)
		j++;
	if (!shell->line[j] && type == '\'')
		return (ft_error(E_UQT, "\'"));
	else if (!shell->line[j] && type == '\"')
		return (ft_error(E_UQT, "\""));
	tmp = ft_substr(shell->line, *i + 1, j - *i - 1);
	if (!tmp)
	{
		ft_error(E_MA, NULL);
		exit(-1);
	}
	push_token(shell, key_t, tmp);
	*i = j;
	return (FALSE);
}

int	redirects(t_minishell *shell, int *i)
{
	if (!ft_strncmp(&shell->line[*i], ">>", 2))
	{
		(*i)++;
		return (push_token(shell, DREDIR_OUT, ft_strdup("")));
	}
	else if (!ft_strncmp(&shell->line[*i], "<<", 2))
	{
		(*i)++;
		return (push_token(shell, HEREDOC, ft_strdup("")));
	}
	else if (shell->line[*i] == '>')
		return (push_token(shell, REDIR_OUT, ft_strdup("")));
	else if (shell->line[*i] == '<')
		return (push_token(shell, REDIR_IN, ft_strdup("")));
	return (TRUE);
}

int	get_dollar(t_minishell *shell, int *i, int key_t)
{
	int		j;
	char	*tmp;

	j = *i + 1;
	while (ft_isdollar(shell->line[j]))
		j++;
	tmp = ft_substr(shell->line, *i, j - *i);
	if (!tmp)
	{
		ft_error(E_MA, NULL);
		exit(-1);
	}
	push_token(shell, key_t, tmp);
	*i = j - 1;
	return (FALSE);
}

int	get_word(t_minishell *shell, int *i, int key_t)
{
	int		j;
	char	*tmp;

	j = *i;
	while (ft_isvalid(shell->line[j]) && shell->line[j])
		j++;
	tmp = ft_substr(shell->line, *i, j - *i);
	if (!tmp)
	{
		ft_error(E_MA, NULL);
		exit(-1);
	}
	push_token(shell, key_t, tmp);
	if (*i == j)
		return (FALSE);
	*i = j - 1;
	return (FALSE);
}
