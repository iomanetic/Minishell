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
#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_elem
{
	void				*key;
	void				*value;
	int					key_t;
	struct s_elem		*next;
}						t_elem;

typedef struct s_heredoc
{
	int					fd;
	char				*name;
	struct s_heredoc	*next;
}						t_heredoc;

typedef struct s_execve
{
	char				*path;
	char				**command;
}						t_execve;

typedef struct s_pipescmd
{
	t_elem				*token;
	int					fd[2];
	int					fd_for_read;
	int					pipe_status;
	struct s_pipescmd	*next;
	struct s_pipescmd	*prev;
}						t_pipescmd;

typedef struct s_minishell
{
	char			*line;
	char			**envp;
	int				status;
	int				exit_status;
	int				redir_out;
	int				redir_in;
	int				rebuild_env_status;
	int				flag_pipe;
	int				here_count;
	int				flag_built;
	t_elem			*env;
	t_elem			*token;
	t_execve		*exec;
	t_pipescmd		*p_cmd;
	t_heredoc		*heredoc;
	t_heredoc		*tmp;
}					t_minishell;

#endif