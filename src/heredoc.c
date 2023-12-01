/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <lohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:15:02 by maharuty          #+#    #+#             */
/*   Updated: 2023/03/17 16:01:35 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini.h"

char	*ft_readline(const char *prefix)
{
	char	*str;

	set_term_attr(1);
	str = readline(prefix);
	set_term_attr(0);
	return (str);
}

static void	write_in_pipe(t_red *head_red, t_general *g_data, char *full_line)
{
	if (head_red->expand_mode_heredoc == EXPAND_VAR)
		full_line = replace_env_var(full_line, g_data);
	if (full_line)
		ft_printf(head_red->heredoc_fd[1], "%s", full_line);
	close(head_red->heredoc_fd[1]);
	exit(0);
}

void	child_heredoc(t_red *head_red, t_general *g_data)
{
	char	*line;
	char	*full_line;

	full_line = ft_strdup("");
	handle_signals(!INTERACTIVE_MODE);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		line = ft_readline("> ");
		if (line == NULL)
		{
			if (full_line[0] != '\0')
				full_line = ft_strjoin_free_first_arg(full_line, "\n");
			break ;
		}
		if ((full_line[0] != '\0' && full_line[0] != '\n') || line[0] == '\0')
			full_line = ft_strjoin_free_first_arg(full_line, "\n");
		if (ft_strcmp(line, head_red->pathname) == 0)
			break ;
		full_line = ft_strjoin_free_first_arg(full_line, line);
	}
	write_in_pipe(head_red, g_data, full_line);
}

int	heredoc(t_red *head_red, t_general *g_data)
{
	pid_t	pid;
	int		status;

	if (pipe(head_red->heredoc_fd) == -1)
		return (1);
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
		child_heredoc(head_red, g_data);
	close(head_red->heredoc_fd[1]);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status) && write(1, "\n", 1))
		return (WTERMSIG(status));
	return (WEXITSTATUS(status));
}
