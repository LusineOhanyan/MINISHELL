/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_io.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <lohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 23:21:43 by maharuty          #+#    #+#             */
/*   Updated: 2023/03/17 15:20:45 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "mini.h"

static void	change_io_first(int **fd, int i, t_pipe pipe)
{
	if (pipe.fd_in != 0)
		dup2(pipe.fd_in, 0);
	if (pipe.fd_out != 1)
		dup2(pipe.fd_out, 1);
	else
		dup2(fd[i][1], 1);
}

static void	change_io_last(int **fd, int i, t_pipe pipe)
{
	if (pipe.fd_out != 1)
		dup2(pipe.fd_out, 1);
	if (pipe.fd_in != 0)
		dup2(pipe.fd_in, 0);
	else
		dup2(fd[i - 1][0], 0);
}

void	change_io(int **fd, int i, int pipe_count, t_pipe pipe)
{
	if (pipe_count > 1)
	{
		if (i == 0)
			change_io_first(fd, i, pipe);
		else if (i == pipe_count - 1)
			change_io_last(fd, i, pipe);
		else
		{
			if (pipe.fd_in != 0)
				dup2(pipe.fd_in, 0);
			else
				dup2(fd[i - 1][0], 0);
			if (pipe.fd_out != 1)
				dup2(pipe.fd_out, 1);
			else
				dup2(fd[i][1], 1);
		}
	}
	else
	{
		dup2(pipe.fd_in, 0);
		dup2(pipe.fd_out, 1);
	}
}
