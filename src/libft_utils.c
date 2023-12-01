/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:01:53 by lohanyan          #+#    #+#             */
/*   Updated: 2023/03/17 16:02:04 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini.h"

char	*ft_strdup_modif(const char *s1, int startIndex, int len)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == 0)
		return (0);
	while (len != 0)
	{
		str[i] = s1[startIndex];
		startIndex++;
		len--;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_trim(char *s1)
{
	int	i;
	int	len;
	int	start_index;
	int	end_index;

	len = ft_strlen(s1);
	if (len > 0)
	{
		i = 0;
		while (s1[i] == 32 && s1[i] != '\0')
		{
			i++;
		}
		start_index = i;
		if (start_index == len)
			return (ft_strdup(""));
		i = len - 1;
		while (s1[i] == 32 && i != 0)
		{
			i--;
		}
		end_index = i + 1;
		return (ft_strdup_modif(s1, start_index, end_index - start_index));
	}
	return (ft_strdup(""));
}

char	*char_to_string(char s1)
{
	char	*res;
	size_t	len;

	len = 2;
	res = malloc(sizeof(char) * len);
	res[0] = s1;
	res[1] = '\0';
	return (res);
}
