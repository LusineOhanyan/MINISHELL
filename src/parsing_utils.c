/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:56:25 by lohanyan          #+#    #+#             */
/*   Updated: 2023/03/17 15:56:40 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini.h"

int	pass_spces(char *line, int i)
{
	while (line[i] != '\0' && ft_strchr(FT_SPACE, line[i]))
		i++;
	return (i);
}

//get everythng that is not in quotes
char	*get_text(char *str, int *i)
{
	int		start_index;
	char	*text;
	int		tmp;

	tmp = 0;
	start_index = (*i);
	text = NULL;
	while (str[(*i)] != '\'' && str[(*i)] != '"' && str[(*i)] != '\0')
	{
		(*i)++;
	}
	if (*i != 0 && str[(*i) - 1] == '$' && str[(*i)] != '\0')
		tmp = -1;
	text = ft_substr(str, start_index, (*i) - (start_index) + tmp);
	return (text);
}

int	pass_word(char *line, int i)
{
	while (line[i] != '\0' && !ft_strchr(METACHARACTERS, line[i]))
	{
		i = pass_quotes(line, i);
		i++;
	}
	return (i);
}

char	*get_word(char *line, int *i)
{
	int	start_index;

	start_index = *i;
	while (line[*i] != '\0' && !ft_strchr(METACHARACTERS, line[*i]))
	{
		*i = pass_quotes(line, *i);
		(*i)++;
	}
	if ((*i) > start_index)
		return (ft_substr(line, start_index, (*i) - start_index));
	else
		return (NULL);
}

int	pass_redir(char *line, int i)
{
	if (line[i] && ft_strchr(REDIRECTIONS, line[i]))
	{
		while (line[i] != '\0' && ft_strchr(REDIRECTIONS, line[i]))
			i++;
		i = pass_spces(line, i);
		i = pass_word(line, i);
		i = pass_spces(line, i);
	}	
	return (i);
}
