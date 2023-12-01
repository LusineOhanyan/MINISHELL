/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maharuty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:08:52 by maharuty          #+#    #+#             */
/*   Updated: 2022/05/16 21:50:06 by maharuty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c, int fd)
{
	return (write(fd, &c, 1));
}

size_t	print_number(int n, int fd)
{
	size_t	len;
	int		*templen;
	long	long_num;

	long_num = (long)n;
	len = 0;
	if (long_num < 0)
	{
		len += print_char('-', fd);
		long_num *= -1;
	}
	templen = print_unsigned_number(long_num, fd);
	len += *templen;
	*templen = 0;
	return (len);
}

int	print_string(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		print_char(s[i], fd);
		i++;
	}
	return (i);
}

int	print_type(va_list args, char format, int fd)
{
	int	len;
	int	*temp_len;

	len = 0;
	temp_len = 0;
	if (format == 'c')
		len += print_char(va_arg(args, int), fd);
	else if (format == 's')
		len += print_string(va_arg(args, char *), fd);
	else if (format == '%')
		len += print_char('%', fd);
	else if (format == 'p')
		len += print_pointer(va_arg(args, uintptr_t), fd);
	else if (format == 'd' || format == 'i')
		len += print_number(va_arg(args, int), fd);
	else if (format == 'u')
		temp_len = print_unsigned_number(va_arg(args, unsigned int), fd);
	else if (format == 'x' || format == 'X')
		temp_len = print_hex(va_arg(args, unsigned int), format, fd);
	if (temp_len)
	{
		len += *temp_len;
		*temp_len = 0;
	}
	return (len);
}

int	ft_printf(int fd, const char *s, ...)
{
	int		i;
	int		len;
	va_list	args;

	va_start(args, s);
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			len += print_type(args, s[i], fd);
		}
		else
		{
			len += print_char(s[i], fd);
		}
		i++;
	}
	va_end(args);
	return (len);
}
