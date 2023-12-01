/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free_first_arg.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <lohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:14:38 by maharuty          #+#    #+#             */
/*   Updated: 2023/03/17 16:11:01 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

char	*ft_strjoin_free_first_arg(char *s1, char const *s2)
{
	char	*ptr;
	char	*ptr1;
	char	*s1_for_free;

	s1_for_free = s1;
	ptr = (char *) malloc(ft_strlen(s1) + ft_strlen((char *)s2) + 1);
	if (ptr == 0)
		return (0);
	ptr1 = ptr;
	while (s1 && *s1 != '\0')
		*ptr++ = *s1++;
	while (s2 && *s2 != '\0')
		*ptr++ = *s2++;
	*ptr = '\0';
	free(s1_for_free);
	return (ptr1);
}

char	*ft_strjoin_free_both_arg(char *s1, char *s2)
{
	char	*ptr;
	char	*ptr1;
	char	*s1_for_free;
	char	*s2_for_free;

	s1_for_free = s1;
	s2_for_free = s2;
	ptr = (char *) malloc(ft_strlen(s1) + ft_strlen((char *)s2) + 1);
	if (ptr == 0)
		return (0);
	ptr1 = ptr;
	while (s1 && *s1 != '\0')
		*ptr++ = *s1++;
	while (s2 && *s2 != '\0')
		*ptr++ = *s2++;
	*ptr = '\0';
	free(s1_for_free);
	free(s2_for_free);
	return (ptr1);
}
