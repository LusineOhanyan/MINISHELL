/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maharuty <maharuty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 00:11:38 by maharuty          #+#    #+#             */
/*   Updated: 2023/03/17 17:35:05 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <dirent.h>
# include "libft.h"
# include "ft_printf.h"
# include <errno.h>
# include <signal.h>
# include <sys/ioctl.h>
# include <string.h>
# include <termios.h>

# define UNEXPECTED "|&;()"
# define FT_SPACE "\n\t "
# define REDIRECTIONS "<>"
# define METACHARACTERS "|&;()<>\n\t "

# define MAXPROCC 600

# define KILLED 100

# define INTERACTIVE_MODE 1

# define SPLITE 111
# define NO_SPLITE 0

# define HEREDOC 1

extern int					g_signal_notifire;

typedef struct s_red		t_red;
typedef struct s_pipe		t_pipe;
typedef struct s_parsing	t_parsing;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct s_parsing
{
	char	**pipes;
}					t_parsing;

typedef struct s_general
{
	int			pipe_count;
	t_env		*head_env;
	char		**env;
	char		**exp;
	char		*line;
	int			exit_status;
	t_pipe		*pipes;
	t_parsing	parse_data;
}					t_general;

typedef struct s_pipe
{
	char	*cmd_name;
	pid_t	pid;	
	int		fd_in;
	int		fd_out;
	int		words_count;
	char	**argv;
	t_red	*head_red;
}					t_pipe;

# define EXPAND_VAR 1
# define NO_EXPAND_VAR 2

typedef struct s_red
{
	int				expand_mode_heredoc;
	int				flag;
	int				heredoc_fd[2];
	char			*pathname;
	struct s_red	*next;
}					t_red;

// parsing
int		check_unexpected(char *str);
char	*ft_strdup_modif(const char *s1, int startIndex, int len);
char	*char_to_string(char s1);
char	*ft_trim(char *s1);
int		check_first_symbol(char *str);
int		check_last_symbol(char *str);
int		check_opening_closing_quote_pair(char *str);
int		check_redir_sytax(char *str);
int		has_errors(char *str);
void	split_by_pipes(t_general *g_data, t_parsing *data);
void	init_structs(t_general *g_data);
int		parsing(t_general *g_data);
void	*ft_malloc(size_t size);
int		pass_quotes(char *str, int i);
void	lst_redir_add_back(t_red **lst, t_red *new);
t_red	*lst_redir_new(void *content, int flag_num);
int		pass_spces(char *line, int i);
int		pass_quotes(char *str, int i);
int		pass_word(char *line, int i);
char	*get_word(char *line, int *i);
int		pass_redir(char *line, int i);
char	*get_text(char *str, int *i);
char	*remove_qutoes(char *s, int *expand_mode_heredoc);
char	*get_inbetween_double_quotes_text(char *str, int *i);
char	*get_inbetween_single_quotes_text(char *str, int *i);
char	*process_dollar_sign_and_quotes(char *line, t_general *g_data);
int		replace_dollar_varables(t_general *g_data, int i);
char	*replace_env_var(char *line, t_general *g_data);
int		**create_pipes(int pipe_count);
void	change_io(int **fd, int i, int pipe_count, t_pipe pipe);
int		exit_status_setter(t_env **head_env, int status);

//env_parsing
t_env	*lst_env_new(void *value, void *key);
void	lst_env_add(t_env **lst, t_env *new);
void	set_env_t_list(t_general *g_data, char **env);
char	*get_value_by_key(char *key, t_env *lst);
void	del_all_env(t_general *g_data);
int		find_and_replace_env_node(t_env *lst, t_env *new);

// rediractions
int		handle_rediractions(t_general *g_data);
int		ft_redir_iter(t_pipe *pipe);
int		heredoc(t_red *head_red, t_general *g_data);

//utils
int		free_array(void	**ptr);
int		free_double_array(void	***ptr);
char	*ft_strjoin_free_first_arg(char *s1, char const *s2);
char	*ft_strjoin_free_both_arg(char *s1, char *s2);
void	close_all_fd(int	**fd, int n);

//temp_utils
void	ft_redir_temp_iter(t_red *lst);
void	ft_env_iter(t_env *lst);

//execute
int		execute(t_general *g_data);
void	handle_signals(int mode);
void	set_term_attr(int on_off);
void	set_execv_path(t_general *g_data, t_pipe *pipe);
int		is_path_abs_or_relative(char *path);
int		is_for_execve(char *cmd, t_general *g_data, t_pipe *pipe);

//free
int		free_general(t_general *g_data);

//builtin
int		is_builtin(char *argv_0);
int		builtin(t_general *g_data, char **argv, int i);
int		ft_echo(char **ptr, int fd);
int		ft_pwd(int fd);
int		ep_strlen(char *s);
int		ft_cd(char **ptr, t_general *data);
int		ft_env(t_general *data, int fd);
int		ft_export(t_general *data, char **ptr, int fd);
int		ft_exit(char **ptr, t_env *head_env);
int		ft_unset(t_general *data, char **ptr);

size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_strdup1(char *s1);
void	get_export(t_general *data);
int		ft_check_str(char *str, t_general *data);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strcmp(char *s1, char *s2);
char	*ft_epstrdup(char *s1);
void	ft_errors(char *str);
void	get_env(t_general *data, char *str);
int		ft_check_str1(char *str, t_general *data);
char	*ft_strjoin1(char *s1, char *s2);
char	*ft_strjoin_modifed(char *s1, char *s2);
void	ft_unset_for_env(t_general *data, char *ptr);
char	*ft_sign(char *s1, int *i, int *j, int *flag);
int		ft_exp_func(char **ptr, t_general *data, int j, int i);
int		ft_cut_for_exp(t_general *data, char *tmp, char *str, int sign);
void	ft_new_malloc(char *str, char **tmp, int i, int flag);
int		ft_cut_for_env(t_general *data, char *tmp, char *str, int sign);
void	ft_check_env(int k, t_general *data, char **tmp);
void	*ft_free_exp(char ***tmp, int j);
void	ft_sort_export(t_general *data, int i);
void	ft_builtins(t_general data, char *cmd, char **tox);
int		ft_errors_for_export(char *str, int *ret_val);
int		ft_check_exit(char **ptr, int i, int j);
void	ft_check_sign(char **ptr, int i);
void	ft_check_sign1(char **ptr, int i);
void	ft_print_error_for_exit(void);
void	ft_print_error_for_non_numeric(char **ptr, int i);
void	ft_new_malloc1(char *str, char **tmp, int i, int flag);
char	*ft_strjoin_for_env(char *s1, char *s2);
int		double_size(char **s);
char	*ft_readline(const char *prefix);
int		is_dir(char *cmd);
void	ft_help_func(char *s2, char **s1, int j, char **str);
void	ft_help_func1(char *s2, char **s1, int j, char **str);
#endif
