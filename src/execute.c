/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <lohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:43:08 by lohanyan          #+#    #+#             */
/*   Updated: 2023/03/21 18:03:54 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	ret_status_from_sig(int status)
{
	if (g_signal_notifire == KILLED)
	{
		g_signal_notifire = 0;
		return (1);
	}
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGKILL)
			return (1);
		if (WTERMSIG(status) == SIGQUIT)
			ft_printf(2, "Quit: 3");
		return (write(1, "\n", 1), WTERMSIG(status) + 128);
	}
	return (-1);
}

int	ret_status(int **fd, t_general *g_data)
{
	int	i;
	int	status;
	int	exit_status;

	close_all_fd(fd, g_data->pipe_count);
	free_double_array((void ***)&fd);
	i = 0;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	while (i < g_data->pipe_count)
	{
		waitpid(g_data->pipes[i].pid, &status, 0);
		if (i == g_data->pipe_count - 1)
			exit_status = WEXITSTATUS(status);
		i++;
	}
	status = ret_status_from_sig(status);
	if (status != -1)
		return (status);
	return (exit_status);
}

void	child(int **fd, int i, t_general *g_data)
{
	handle_signals(!INTERACTIVE_MODE);
	change_io(fd, i, g_data->pipe_count, g_data->pipes[i]);
	close_all_fd(fd, g_data->pipe_count);
	if (is_builtin(g_data->pipes[i].argv[0]))
		exit (builtin(g_data, g_data->pipes[i].argv, i));
	if (g_data->pipes[i].words_count > 0)
		g_data->pipes[i].cmd_name
			= ft_strdup(g_data->pipes[i].argv[0]);
	if (is_for_execve(g_data->pipes[i].cmd_name,
			g_data, &g_data->pipes[i]))
		execve(g_data->pipes[i].cmd_name,
			g_data->pipes[i].argv, g_data->env);
	ft_printf(2, "Minishell: %s: %s\n",
		g_data->pipes[i].cmd_name, strerror(errno));
	exit(127);
}

static int	fork_fail(t_general *g_data)
{
	g_signal_notifire = KILLED;
	kill(g_data->pipes[0].pid, SIGKILL);
	perror("fork");
	return (1);
}

int	execute(t_general *g_data)
{
	int	i;
	int	**fd;

	i = 0;
	if (g_data->pipe_count == 1 && g_data->pipes[0].argv)
		if (is_builtin(g_data->pipes[0].argv[0]))
			return (builtin(g_data, g_data->pipes[0].argv, 0));
	fd = create_pipes(g_data->pipe_count);
	if (fd == NULL)
		return (127);
	while (i < g_data->pipe_count)
	{
		if (g_data->pipes[i].argv)
		{
			g_data->pipes[i].pid = fork();
			if (g_data->pipes[i].pid == -1 && fork_fail(g_data))
				break ;
			if (g_data->pipes[i].pid == 0)
				child(fd, i, g_data);
		}
		i++;
	}
	return (ret_status(fd, g_data));
}
