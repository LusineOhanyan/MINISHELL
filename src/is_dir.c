/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <lohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 20:28:43 by lohanyan          #+#    #+#             */
/*   Updated: 2023/03/17 20:32:11 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	is_dir(char *cmd)
{
	if (opendir(cmd))
	{
		ft_printf(2, "minishell: %s: is a directory\n", cmd);
		exit (126);
	}
	return (0);
}
