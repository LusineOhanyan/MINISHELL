/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <lohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:04:59 by lohanyan          #+#    #+#             */
/*   Updated: 2023/03/17 15:57:31 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	set_args(t_pipe *pipe, char *line)
{
	int		i;
	int		j;
	char	*word;

	if (pipe->words_count == 0)
		return ;
	pipe->argv = malloc(sizeof (char *) * (pipe->words_count + 1));
	pipe->argv[pipe->words_count] = NULL;
	i = 0;
	j = 0;
	word = NULL;
	while (line[i] != '\0')
	{
		i = pass_spces(line, i);
		i = pass_redir(line, i);
		word = get_word(line, &i);
		if (word != NULL)
			pipe->argv[j++] = word;
	}
}

int	get_redir_flag(char *line, int *i)
{
	int		flag;

	flag = 9;
	if (line[*i] == '>' && line[(*i) + 1] == '>')
	{
		flag = O_APPEND;
		*i = (*i) + 2;
	}
	else if (line[*i] == '<' && line[(*i) + 1] == '<')
	{
		flag = HEREDOC;
		*i = (*i) + 2;
	}
	else if (line[*i] == '>')
	{
		flag = O_TRUNC;
		(*i)++;
	}
	else if (line[*i] == '<')
	{
		flag = O_RDONLY;
		(*i)++;
	}
	return (flag);
}

static void	set_rediractions_helper(t_pipe *pipe, char *line, int flag, int *i)
{
	char	*word;

	*i = pass_spces(line, *i);
	word = get_word(line, i);
	if (pipe->head_red == NULL)
		pipe->head_red = lst_redir_new(word, flag);
	else
		lst_redir_add_back(&pipe->head_red, lst_redir_new(word, flag));
	free(word);
}

void	set_rediractions(t_pipe *pipe, char *line)
{
	int		i;
	int		flag;

	i = 0;
	while (line[i] != '\0')
	{
		i = pass_spces(line, i);
		flag = get_redir_flag(line, &i);
		if (flag == 9 && line[i] != '\0')
		{
			i = pass_spces(line, i);
			pipe->words_count += 1;
			free(get_word(line, &i));
		}
		if (flag != 9)
			set_rediractions_helper(pipe, line, flag, &i);
	}
}

int	parsing(t_general *g_data)
{
	int	i;

	i = 0;
	while (g_data->parse_data.pipes[i])
	{
		g_data->pipes[i].fd_in = 0;
		g_data->pipes[i].fd_out = 1;
		g_data->pipes[i].head_red = NULL;
		g_data->pipes[i].words_count = 0;
		g_data->pipes[i].argv = NULL;
		g_data->pipes[i].cmd_name = NULL;
		set_rediractions(&g_data->pipes[i], g_data->parse_data.pipes[i]);
		set_args(&g_data->pipes[i], g_data->parse_data.pipes[i]);
		replace_dollar_varables(g_data, i);
		i++;
	}
	return (handle_rediractions(g_data));
}
