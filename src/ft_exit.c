/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <lohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:56:44 by tumolabs          #+#    #+#             */
/*   Updated: 2023/03/17 20:46:13 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int						size_of_num(char *str);
unsigned long long int	ft_atoi_modifed(const char *str);

int	ft_exit(char **ptr, t_env *head_env)
{
	int						i;
	int						j;
	unsigned long long int	tiv;
	char					*arr_for_free;

	i = 1;
	j = 0;
	if (!ptr[i] && ft_printf(2, "exit\n"))
		exit(ft_atoi(get_value_by_key("?", head_env)));
	arr_for_free = ptr[1];
	ptr[1] = ft_strtrim(ptr[1], FT_SPACE);
	free(arr_for_free);
	tiv = ft_atoi_modifed(ptr[i]);
	if (ft_check_exit(&ptr[i], i, j) != 0)
		return (1);
	if (size_of_num(ptr[i]) > 19)
		ft_print_error_for_non_numeric(ptr, i);
	if (size_of_num(ptr[i]) == 19 && ptr[i][0] == '-')
		ft_check_sign1(ptr, i);
	else if (size_of_num(ptr[i]) == 19)
		ft_check_sign(ptr, i);
	ft_printf(2, "exit\n");
	exit(tiv);
	return (0);
}

int	ft_check_exit(char **ptr, int i, int j)
{
	if (ptr[0][0] == '-' || ptr[0][0] == '+')
		j++;
	while (ptr[0][j])
	{
		if (!(ptr[0][j] >= 48 && ptr[0][j] <= 57))
		{
			ft_printf(2, "exit\n");
			ft_printf(2, "Minishell: exit: %s: numeric\
 argument required\n", ptr[0]);
			exit(255);
		}
		j++;
	}
	if (ptr[i] != NULL)
	{
		ft_printf(2, "exit\n");
		ft_printf(2, "Minishell : exit: too many arguments\n");
		return (1);
	}
	return (0);
}
