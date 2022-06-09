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

int	redirect_syntx(t_elem **tmp)
{
	if ((*tmp)->key_t == HEREDOC)
		return (find_something(tmp, (*tmp)->key_t));
	else if ((*tmp)->key_t == DREDIR_OUT)
		return (find_something(tmp, (*tmp)->key_t));
	else if ((*tmp)->key_t == REDIR_OUT)
		return (find_something(tmp, (*tmp)->key_t));
	else if ((*tmp)->key_t == REDIR_IN)
		return (find_something(tmp, (*tmp)->key_t));
	return (FALSE);
}

int	find_something(t_elem **tmp, int key_t)
{
	while ((*tmp) && (*tmp)->key_t == SEP)
		*tmp = (*tmp)->next;
	if (key_t == PIPE)
		return (ft_ispipe(&(*tmp)->next));
	else if (key_t == HEREDOC || key_t == DREDIR_OUT
		|| key_t == REDIR_IN || key_t == REDIR_OUT)
		return (ft_isredirect(&(*tmp)->next));
	return (FALSE);
}

int	check_syntx(t_elem *tmp)
{
	t_elem	*tmp_2;

	tmp_2 = tmp;
	while (tmp_2 && tmp_2->key_t == SEP)
		tmp_2 = tmp_2->next;
	if (!tmp_2)
		return (FALSE);
	if (tmp_2->key_t == PIPE)
		return (ft_error(E_SE, NULL));
	while (tmp)
	{
		if (tmp->key_t == PIPE)
			if (find_something(&tmp, tmp->key_t))
				return (TRUE);
		if (redirect_syntx(&tmp))
			return (TRUE);
		tmp = tmp->next;
	}
	return (FALSE);
}

int	ft_openenv(t_minishell *shell, char **elem)
{
	int	i;

	i = 0;
	while ((*elem)[i])
	{
		if ((*elem)[i] == '\\')
			return (ft_error(E_US, "\\"));
		else if ((*elem)[i] == '$')
			find_dollar(shell, elem, i);
		if ((*elem)[i])
			i++;
	}
	return (FALSE);
}
