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

void	handler(int signal)
{
	if (signal == SIGINT)
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		return ;
	}
}

void	handler_heredoc(int signal)
{
	if (signal == SIGINT)
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		exit(1);
	}
}

int	accept_signals(void)
{
	if (signal(SIGINT, &handler) == SIG_ERR)
		return (ft_error(E_SAE, NULL));
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		return (ft_error(E_SAE, NULL));
	return (FALSE);
}
