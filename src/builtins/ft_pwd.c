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

int	ft_pwd(t_minishell *shell)
{
	char	buf[PATH_MAX];

	if (!getcwd(buf, PATH_MAX))
	{
		ft_putstr_fd(strerror(errno), STDOUT_FILENO);
		shell->exit_status = 128;
		return (TRUE);
	}
	ft_putstr_fd(buf, STDOUT_FILENO);
	write(STDOUT_FILENO, "\n", 1);
	shell->exit_status = 0;
	return (TRUE);
}
