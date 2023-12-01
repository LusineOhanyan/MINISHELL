/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rediractions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <lohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:39:29 by lohanyan          #+#    #+#             */
/*   Updated: 2023/03/17 14:46:51 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static int	heredoc_iter(t_pipe *pipe, t_general *g_data)
{
	t_red	*temp;

	temp = pipe->head_red;
	while (temp)
	{
		if (temp->flag == HEREDOC)
		{
			if (heredoc(temp, g_data))
				return (1);
		}
		temp = temp->next;
	}
	return (0);
}

int	handle_rediractions(t_general *g_data)
{
	int	i;

	i = -1;
	while (g_data->pipe_count > ++i)
	{
		if (heredoc_iter(&g_data->pipes[i], g_data))
			return (1);
	}	
	i = -1;
	while (g_data->pipe_count > ++i)
	{
		if (ft_redir_iter(&g_data->pipes[i]))
			return (1);
	}
	return (0);
}

int	ft_redir_iter_for_write(t_pipe *pipe, t_red	*temp)
{
	if (pipe->fd_out != 1)
		close(pipe->fd_out);
	pipe->fd_out = open(temp->pathname, O_CREAT | temp->flag | O_RDWR, 0777);
	if (pipe->fd_out == -1)
	{
		ft_printf(2, "Minishell: open: %s: %s\n", \
		temp->pathname, strerror(errno));
		return (1);
	}
	return (0);
}

int	ft_redir_iter_for_read(t_pipe *pipe, t_red	*temp)
{
	if (pipe->fd_in != 0)
		close(pipe->fd_in);
	pipe->fd_in = open(temp->pathname, temp->flag);
	if (pipe->fd_in == -1)
	{
		ft_printf(2, "Minishell: open: %s: %s\n", \
		temp->pathname, strerror(errno));
		return (1);
	}
	return (0);
}

int	ft_redir_iter(t_pipe *pipe)
{
	t_red	*temp;	

	temp = pipe->head_red;
	while (temp)
	{
		if (temp->flag == O_TRUNC || temp->flag == O_APPEND)
		{
			if (ft_redir_iter_for_write(pipe, temp) == 1)
				return (1);
		}
		else if (temp->flag == O_RDONLY)
		{
			if (ft_redir_iter_for_read(pipe, temp))
				return (1);
		}
		else if (temp->flag == HEREDOC)
		{
			if (pipe->fd_in != 0)
				close(pipe->fd_in);
			pipe->fd_in = temp->heredoc_fd[0];
		}
		temp = temp->next;
	}
	return (0);
}
