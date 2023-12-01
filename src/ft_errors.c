/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <lohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:20:52 by tumolabs          #+#    #+#             */
/*   Updated: 2023/03/17 19:00:43 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	help_function_for_export(char *str)
{
	int		i;

	i = 1;
	while (str && str[i] && str[i] != '=' && str[i - 1] != '+')
	{
		if (str[i] == '+' && str[i + 1] != '=')
		{
			ft_printf(2, "minishell: export: %s: not a valid identifier\n", str);
			return (1);
		}
		if ((!(str[i] >= 65 && str[i] <= 90))
			&& (!(str[i] >= 97 && str[i] <= 122))
			&& (str[i] != '_')
			&& str[i] != '+' && (!(str[i] >= 48 && str[i] <= 57)))
		{
			ft_printf(2, "minishell: export: %s: not a valid identifier\n", str);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_errors_for_export(char *str, int *ret_val)
{
	int	i;

	i = 0;
	if ((!(str[0] >= 65 && str[0] <= 90))
		&& (!(str[0] >= 97 && str[0] <= 122)) && (str[0] != '_'))
	{
		*ret_val = 1;
		ft_printf(2, "minishell: export: %s: not a valid identifier\n", str);
		return (1);
	}
	else
	{
		if (help_function_for_export(str) == 1)
		{
			*ret_val = 1;
			return (1);
		}
	}
	return (0);
}
