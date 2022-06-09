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
#include "../../includes/minishell.h"

int	redirect_out(t_minishell *shell, t_elem **redir)
{
	int	fd_out;

	if (!(*redir)->next)
		return (FALSE);
	*redir = (*redir)->next;
	while (*redir && (*redir)->key_t == SEP)
		*redir = (*redir)->next;
	fd_out = open((char *)(*redir)->value, \
		O_WRONLY | O_CREAT | O_TRUNC, 0664);
	(*redir)->key_t = REDIR_OUT;
	if (fd_out == -1)
	{
		shell->exit_status = 1;
		return (ft_error(E_OF, NULL));
	}
	shell->redir_out = fd_out;
	ft_realloc(&(*redir)->value, "");
	return (FALSE);
}

int	dredirect_out(t_minishell *shell, t_elem **redir)
{
	int	fd_out;

	if (!(*redir)->next)
		return (FALSE);
	*redir = (*redir)->next;
	while (*redir && (*redir)->key_t == SEP)
		*redir = (*redir)->next;
	fd_out = open((char *)(*redir)->value, \
		O_WRONLY | O_CREAT | O_APPEND, 0664);
	(*redir)->key_t = DREDIR_OUT;
	if (fd_out == -1)
	{
		shell->exit_status = 1;
		return (ft_error(E_OF, NULL));
	}
	shell->redir_out = fd_out;
	ft_realloc(&(*redir)->value, "");
	return (FALSE);
}

int	redirect_in(t_minishell *shell, t_elem **redir)
{
	int	fd_in;

	if (!(*redir)->next)
		return (FALSE);
	*redir = (*redir)->next;
	while (*redir && (*redir)->key_t == SEP)
		*redir = (*redir)->next;
	fd_in = open((char *)(*redir)->value, O_RDONLY, 0777);
	(*redir)->key_t = REDIR_IN;
	if (fd_in == -1)
	{
		shell->exit_status = 1;
		return (ft_error(E_OF, NULL));
	}
	shell->redir_in = fd_in;
	ft_realloc(&(*redir)->value, "");
	return (FALSE);
}
