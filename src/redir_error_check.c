/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_error_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <lohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:28:34 by maharuty          #+#    #+#             */
/*   Updated: 2023/03/17 14:51:07 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static int	check_redir_sytax_helper(char *str, int *i)
{
	char	c;

	c = str[(*i)];
	if (str[(*i) + 1] == '\0')
		return (1);
	else if (str[(*i) + 1] == c)
		(*i)++;
	(*i)++;
	(*i) = pass_spces(str, (*i));
	if (str[(*i)] == '\0')
		return (1);
	if (str[(*i)] && ft_strchr(METACHARACTERS, str[(*i)]))
		return (1);
	return (0);
}

int	check_redir_sytax(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (str[i] != '\0')
	{
		while (i != j)
		{
			j = i;
			i = pass_quotes(str, i);
		}
		if (str[i] && ft_strchr(REDIRECTIONS, str[i]))
			if (check_redir_sytax_helper(str, &i) == 1)
				return (1);
		if (str[i])
			i++;
	}
	return (0);
}
