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

int	ft_error(char *message, char *token)
{
	ft_putstr_fd(message, STDERR_FILENO);
	if (token)
	{
		ft_putstr_fd(token, STDERR_FILENO);
		ft_putchar_fd('\'', STDERR_FILENO);
	}
	ft_putstr_fd("\n", STDERR_FILENO);
	return (TRUE);
}
