/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_qutoes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maharuty <maharuty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:14:07 by maharuty          #+#    #+#             */
/*   Updated: 2023/03/16 23:44:49 by maharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

char	*remove_qutoes(char *s, int *expand_mode_heredoc)
{
	char	*result;
	int		i;
	int		j;
	char	c;

	result = malloc(ft_strlen(s) + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == '"' || s[i] == '\'')
		{
			*expand_mode_heredoc = NO_EXPAND_VAR;
			c = s[i++];
			while (s[i] && s[i] != c)
				result[j++] = s[i++];
		}
		else
			result[j++] = s[i];
		i++;
	}
	result[j] = '\0';
	return (free(s), result);
}
