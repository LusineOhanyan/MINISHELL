/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <lohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 23:28:04 by maharuty          #+#    #+#             */
/*   Updated: 2023/03/17 20:31:38 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static int	pass_zero(char *ptr)
{
	int	i;

	i = 0;
	if (ptr[0] == '-' || ptr[0] == '+')
		i++;
	while (ptr[i] == '0')
		i += 1;
	return (i);
}

int	size_of_num(char *str)
{
	int	i;
	int	j;

	j = pass_zero(str);
	i = 0;
	while (str[i])
		i++;
	return (i - j);
}

void	ft_check_sign1(char **ptr, int i)
{
	if (ft_strcmp(&ptr[1][pass_zero(ptr[1])], "9223372036854775808") > 0)
		ft_print_error_for_non_numeric(ptr, i);
}

void	ft_check_sign(char **ptr, int i)
{
	if (ft_strcmp(&ptr[i][pass_zero(ptr[1])], "9223372036854775807") > 0)
		ft_print_error_for_non_numeric(ptr, i);
}

void	ft_print_error_for_non_numeric(char **ptr, int i)
{
	ft_printf(2, "exit\n");
	ft_printf(2, "Minishell: exit %s : numeric argument  required\n", ptr[i]);
	exit(255);
}
