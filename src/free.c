/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <lohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 23:55:32 by maharuty          #+#    #+#             */
/*   Updated: 2023/03/17 20:30:27 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	free_parsing(t_parsing *pars_data)
{
	free_double_array((void ***)&pars_data->pipes);
}

void	free_red(t_red *head_red)
{
	t_red	*prev;

	prev = head_red;
	while (head_red)
	{
		if (head_red->flag == HEREDOC)
			close(head_red->heredoc_fd[0]);
		free_array((void **)&head_red->pathname);
		prev = head_red;
		head_red = head_red->next;
		free(prev);
	}
}

void	free_pipes(t_pipe *pipes, int pipe_count)
{
	int	i;

	i = 0;
	if (pipes == NULL)
		return ;
	while (i < pipe_count)
	{
		if (pipes[i].fd_in != 0)
			close(pipes[i].fd_in);
		if (pipes[i].fd_out != 1)
			close(pipes[i].fd_out);
		free_array((void **)&pipes[i].cmd_name);
		free_red(pipes[i].head_red);
		free_double_array((void ***)&pipes[i].argv);
		i++;
	}
}

int	free_general(t_general *g_data)
{
	free_parsing(&g_data->parse_data);
	free_array((void **)&g_data->line);
	free_pipes(g_data->pipes, g_data->pipe_count);
	free_array((void **)&g_data->pipes);
	g_data->pipes = NULL;
	return (1);
}
