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

int	find_heredoc(t_minishell *shell)
{
	t_elem	*tmp;

	tmp = shell->token;
	while (tmp)
	{
		if (tmp->key_t == HEREDOC)
			if (ft_heredoc(shell, tmp))
				return (TRUE);
		tmp = tmp->next;
	}
	return (FALSE);
}

int	ft_changefd(t_minishell *shell, t_elem **token)
{
	char	*tmp;

	*token = (*token)->next;
	while ((*token) && ft_istoken((*token)->key_t))
		*token = (*token)->next;
	(*token)->key_t = HEREDOC;
	tmp = (*token)->value;
	(*token)->value = ft_strdup("");
	free(tmp);
	shell->heredoc->fd = open(shell->heredoc->name, O_RDONLY, 0777);
	if (shell->heredoc->fd == -1)
		return (ft_error(E_OF, NULL));
	shell->redir_in = shell->heredoc->fd;
	shell->heredoc = shell->heredoc->next;
	return (FALSE);
}

int	ft_openredirects(t_minishell *shell, t_elem *token)
{
	while (token)
	{
		if (token->key_t == REDIR_OUT)
		{
			if (redirect_out(shell, &token))
				return (TRUE);
		}
		else if (token->key_t == DREDIR_OUT)
		{
			if (dredirect_out(shell, &token))
				return (TRUE);
		}
		else if (token->key_t == REDIR_IN)
		{
			if (redirect_in(shell, &token))
				return (TRUE);
		}
		else if (token->key_t == HEREDOC)
			if (ft_changefd(shell, &token))
				return (TRUE);
		token = token->next;
	}
	return (FALSE);
}

int	shell_preparser(t_minishell *shell)
{
	t_elem	*tmp;

	tmp = shell->token;
	if (find_heredoc(shell))
	{
		shell->tmp = shell->heredoc;
		shell->exit_status = 258;
		return (TRUE);
	}
	shell->tmp = shell->heredoc;
	if (check_syntx(tmp))
	{
		shell->exit_status = 258;
		return (TRUE);
	}
	tmp = shell->token;
	while (tmp)
	{
		if (tmp->key_t == DOUB_QUO || tmp->key_t == DOLLAR)
			ft_openenv(shell, (char **)&tmp->value);
		tmp = tmp->next;
	}
	return (FALSE);
}
