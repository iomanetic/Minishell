/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:31:00 by tyuuki            #+#    #+#             */
/*   Updated: 2022/06/08 17:26:56 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_ispipe(t_elem **tmp)
{
	t_elem	*tmp_2;

	tmp_2 = *tmp;
	while (tmp_2 && tmp_2->key_t == SEP)
		tmp_2 = tmp_2->next;
	if (!tmp_2)
		return (ft_error(E_SE, NULL));
	if (tmp_2->key_t == PIPE)
		return (ft_error(E_SE, NULL));
	return (FALSE);
}

int	ft_isredirect(t_elem **tmp)
{
	t_elem	*tmp_2;

	tmp_2 = *tmp;
	while (tmp_2 && tmp_2->key_t == SEP)
		tmp_2 = tmp_2->next;
	if (!tmp_2)
		return (ft_error(E_SE, NULL));
	if (tmp_2->key_t != WORD && tmp_2->key_t != DOLLAR \
		&& tmp_2->key_t != DOUB_QUO && tmp_2->key_t != SING_QUO)
		return (ft_error(E_SE, NULL));
	return (FALSE);
}

char	*search_env(t_minishell *shell, char *str)
{
	t_elem	*tmp;

	tmp = shell->env;
	if (!ft_strncmp("?", str, 1))
		return (ft_itoa(shell->exit_status));
	while (tmp)
	{
		if (!ft_strcmp((char *)tmp->key, str))
			return (ft_strdup((char *)tmp->value));
		tmp = tmp->next;
	}
	return (NULL);
}

void	find_dollar_help(char **tmp_3, char **str, int i, int j)
{
	char	*tmp;
	char	*tmp_2;

	tmp_2 = ft_substr(*str, 0, i);
	tmp = ft_strjoin(tmp_2, *tmp_3);
	free(tmp_2);
	tmp_2 = ft_substr(*str, j, ft_strlen(&(*str)[j]));
	free(*str);
	*str = ft_strjoin(tmp, tmp_2);
	free(tmp_2);
	free(tmp);
	free(*tmp_3);
}

void	find_dollar(t_minishell *shell, char **str, int i)
{
	int		j;
	char	*tmp;
	char	*tmp_2;
	char	*tmp_3;

	j = i + 1;
	norm_help_dollar(str, &j);
	tmp = ft_substr(*str, i + 1, j - i - 1);
	tmp_3 = search_env(shell, tmp);
	free(tmp);
	if (!tmp_3)
	{
		tmp_2 = ft_substr(*str, 0, i);
		tmp = ft_strjoin(tmp_2, &(*str)[j]);
		free(*str);
		free(tmp_2);
		*str = tmp;
	}
	else
		find_dollar_help(&tmp_3, str, i, j);
}
