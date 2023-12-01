/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <lohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 23:22:56 by maharuty          #+#    #+#             */
/*   Updated: 2023/03/21 17:10:43 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "mini.h"

void	*ft_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		exit (1);
	return (ptr);
}

int	**create_pipes(int pipe_count)
{
	int	i;
	int	**fd;

	i = 0;
	fd = ft_malloc(sizeof(int *) * (pipe_count));
	while (i < pipe_count - 1)
	{
		fd[i] = ft_malloc(sizeof(int) * 2);
		if (pipe(fd[i]) == -1)
		{
			perror("Minishell: pipe:");
			while (i != -1)
			{
				close(fd[i][0]);
				close(fd[i][1]);
				free(fd[i]);
				i--;
			}
			free(fd);
			return (NULL);
		}
		i++;
	}
	fd[i] = NULL;
	return (fd);
}
