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

void	ft_signals_heredoc(void)
{
	if (signal(SIGINT, handler_heredoc) == SIG_ERR)
	{
		ft_error(E_SAE, NULL);
		exit (-1);
	}
}

int	heredoc_normhelp(t_minishell *shell, t_elem *token, char *line)
{
	t_heredoc	*tmp;
	char		*join;

	tmp = shell->heredoc;
	while (tmp->next)
		tmp = tmp->next;
	ft_signals_heredoc();
	while (1)
	{
		ft_putstr_fd("> ", STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
		if (!line)
			exit(0);
		join = ft_strjoin((char *)token->value, "\n");
		if (!ft_strncmp(line, join, ft_strlen(line)))
			exit(0);
		if (write(tmp->fd, line, ft_strlen(line)) == -1)
		{
			ft_error(E_WE, NULL);
			exit(-1);
		}
		free(line);
		free(join);
	}
}

int	ft_heredoc(t_minishell *shell, t_elem *token)
{
	pid_t	pid;
	char	*line;

	line = NULL;
	token = token->next;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	while (token && token->key_t == SEP)
		token = token->next;
	if (!token)
		return (ft_error(E_SE, NULL));
	if (ft_istoken(token->key_t))
		return (ft_error(E_SE, NULL));
	if (ft_lstadd_back_heredoc(&shell->heredoc, \
	ft_newheredoc(return_filename(shell))))
		return (TRUE);
	pid = fork();
	if (pid < 0)
		return (ft_error(E_FI, NULL));
	if (pid == 0)
		heredoc_normhelp(shell, token, line);
	waitpid(pid, &shell->exit_status, 0);
	close(shell->heredoc->fd);
	ft_exit_status(shell);
	return (FALSE);
}
