/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status_setter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maharuty <maharuty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 23:40:04 by maharuty          #+#    #+#             */
/*   Updated: 2023/03/17 12:52:44 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	exit_status_setter(t_env **head_env, int status)
{
	char	*str_status;

	str_status = ft_itoa(status);
	lst_env_add(head_env, lst_env_new("?", str_status));
	free_array((void **)&str_status);
	return (1);
}
