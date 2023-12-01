/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_sign_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:34:52 by lohanyan          #+#    #+#             */
/*   Updated: 2023/03/20 21:51:34 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

char	*get_variable_name(char *line, int *i)
{
	int	start_num;

	start_num = (*i);
	if (line[*i] == '?' && ++(*i))
		return (ft_strdup("?"));
	while (line[(*i)] != '\0' && (ft_isalpha(line[(*i)])
			|| ft_isdigit(line[(*i)]) || line[(*i)] == '_'))
		(*i)++;
	if ((*i) > start_num)
		return (ft_substr(line, start_num, (*i) - start_num));
	return (NULL);
}

char	*get_value_by_key(char *key, t_env *lst)
{
	while (lst)
	{
		if (ft_strcmp(key, lst->key) == 0)
			return (lst->value);
		lst = lst->next;
	}
	return (NULL);
}

char	*process_dollar_sign_and_quotes(char *line, t_general *g_data)
{
	int		i;
	char	*final_line;
	char	*temp;

	i = 0;
	temp = NULL;
	final_line = NULL;
	while (line[i] != '\0')
	{
		temp = get_inbetween_single_quotes_text(line, &i);
		final_line = ft_strjoin_free_both_arg(final_line, temp);
		temp = get_inbetween_double_quotes_text(line, &i);
		if (!temp)
			temp = get_text(line, &i);
		if (temp)
		{
			temp = replace_env_var(temp, g_data);
			final_line = ft_strjoin_free_both_arg(final_line, temp);
		}
	}
	free(line);
	return (final_line);
}

void	f( char c, char **final_line)
{
	char	a[2];

	a[0] = c;
	a[1] = '\0';
	*final_line = ft_strjoin_free_first_arg(*final_line, a);
}

//$HOME help "hello $aa"$MM text$

char	*replace_env_var(char *line, t_general *g_data)
{
	int		i;
	char	*final_line;
	char	*temp;

	i = 0;
	final_line = NULL;
	while (line[i] != '\0')
	{
		if (line[i] == '$' && ++i)
		{
			g_signal_notifire = SPLITE;
			temp = get_variable_name(line, &i);
			if (temp != NULL)
				final_line = ft_strjoin_free_first_arg(final_line,
						get_value_by_key(temp, g_data->head_env));
			else if (line[i] == '\0')
				final_line = ft_strjoin_free_first_arg(final_line, "$");
			free_array((void **)&temp);
		}
		if (line[i] && line[i] != '$')
			f(line[i], &final_line);
		if (line[i] != '\0' && line[i] != '$')
			i++;
	}
	return (free_array((void **)&line), final_line);
}
