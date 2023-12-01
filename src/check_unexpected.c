/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_unexpected.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <lohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:33:07 by lohanyan          #+#    #+#             */
/*   Updated: 2023/03/17 20:18:52 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static void	loop_untill_unexpected(char *str, int *i, int *flag)
{
	int	j;

	j = -1;
	while (str[(*i)] && !ft_strchr(UNEXPECTED, str[(*i)]))
	{
		j = (*i);
		(*i) = pass_quotes(str, (*i));
		if (j != (*i) && ++(*i))
			*flag = 1;
		if (str[(*i)] && !ft_strchr(METACHARACTERS, str[(*i)]))
			*flag = 1;
		if (str[(*i)])
			(*i)++;
	}
}

int	check_unexpected(char *str)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = -1;
	flag = 0;
	while (str[i])
	{
		if (str[i] && (flag == 0 || str[i + 1] == '\0')
			&& ft_strchr(UNEXPECTED, str[i]))
			return (1);
		else if (i != 0)
			i++;
		flag = 0;
		loop_untill_unexpected(str, &i, &flag);
	}
	return (0);
}
