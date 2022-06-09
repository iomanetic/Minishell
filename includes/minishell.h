/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:31:00 by tyuuki            #+#    #+#             */
/*   Updated: 2022/06/08 17:25:41 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../libs/libft/libft.h"
# include "../libs/get_next_line/get_next_line.h"
# include "defines.h"
# include "structs.h"

# ifndef MAIN_FUNC
#  define MAIN_FUNC

void		envp_init(t_minishell *shell, char **envp);
void		minishell_init(t_minishell *shell);
int			accept_signals(void);
int			shell_parser(t_minishell *shell);

# endif

# ifndef SIGNALS
#  define SIGNALS

void		handler_heredoc(int signal);
# endif

# ifndef BUILTINS
#  define BUILTINS

int			redirects(t_minishell *shell, int *i);
int			redirect_out(t_minishell *shell, t_elem **redir);
int			redirect_in(t_minishell *shell, t_elem **redir);
int			dredirect_out(t_minishell *shell, t_elem **redir);
int			ft_heredoc(t_minishell *shell, t_elem *token);
int			ft_pwd(t_minishell *shell);
int			ft_env(t_minishell *shell);
int			ft_echo(t_minishell *shell);
int			ft_export(t_minishell *shell);
int			ft_unset(t_minishell *shell);
int			ft_cd(t_minishell *shell);
void		ft_exit(t_minishell *shell);
int			check_export(t_minishell *shell);
int			search_builtins(t_minishell *shell, int flag);
# endif

# ifndef LEXER_FUNC
#  define LEXER_FUNC

int			push_token(t_minishell *shell, int key_t, char *value);
int			search_quetos(t_minishell *shell, int *i, char type, int key_t);
int			get_dollar(t_minishell *shell, int *i, int key_t);
int			get_word(t_minishell *shell, int *i, int key_t);
int			ft_isdollar(char c);
int			lexer(t_minishell *shell);
int			ft_isvalid(char c);
void		ft_exit_status(t_minishell *shell);
# endif

# ifndef PARS_FUNC
#  define PARS_FUNC

void		find_dollar(t_minishell *shell, char **str, int i);
int			shell_preparser(t_minishell *shell);
int			ft_openenv(t_minishell *shell, char **elem);
int			exec(t_minishell *shell);
int			find_something(t_elem **tmp, int key_t);
int			check_syntx(t_elem *tmp);
int			ft_ispipe(t_elem **tmp);
int			ft_isredirect(t_elem **tmp);
int			ft_openredirects(t_minishell *shell, t_elem *token);
void		find_path(t_minishell *shell, t_elem *token);
int			pipeistrue(t_elem *token);
int			write_x2list(t_minishell *shell);
int			find_cmd(t_elem *tmp);
int			closepipes(t_minishell *shell, t_pipescmd *cmd, pid_t pid);
void		for_pipes(t_minishell *shell, int flag);
void		ft_exit_status(t_minishell *shell);
int			find_cmd(t_elem *tmp);
int			something_exec(t_minishell *shell, int flag);
# endif

# ifndef UTILS
#  define UTILS

int			ft_error(char *message, char *token);
int			ft_isspace(char c);
t_elem		*ft_lstnew(void *key, void *value, int key_t);
t_heredoc	*ft_newheredoc(char *name);
char		*return_filename(t_minishell *shell);
void		ft_cleaner(t_minishell *shell);
void		ft_lstadd_back(t_elem **lst, t_elem *new);
int			ft_lstadd_back_heredoc(t_heredoc **lst, t_heredoc *new);
void		ft_realloc(void **line, char *new_elem);
void		ft_freex2arr(char **arr);
void		ft_clean_x2list(t_pipescmd *cmd);
void		kill_zombie(t_minishell *shell);
void		ft_backtohead(t_pipescmd **lst);
int			ft_istoken(int key_t);
char		**ft_split_shell(t_elem *token);
int			check_synt_export(char symb, int flag);
void		norm_help_dollar(char **str, int *j);
# endif

# ifndef READLINE_FUNC
#  define READLINE_FUNC

void		rl_replace_line(const char *text, int clear_undo);
# endif

#endif