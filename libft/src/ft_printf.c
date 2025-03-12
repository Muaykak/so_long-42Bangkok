/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <srussame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 07:02:06 by srussame          #+#    #+#             */
/*   Updated: 2024/09/24 18:23:53 by muaykak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_do_printf_sub1(const char *str, va_list args, int *count);
static int	ft_do_printf_sub2(const char *str, va_list args, int *count, int i);
static int	ft_do_printf(const char *str, va_list args, int *count);

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	if (!str)
		return (-1);
	count = 0;
	va_start(args, str);
	if (ft_do_printf(str, args, &count) == -1)
		return (-1);
	va_end(args);
	return (count);
}

static int	ft_do_printf(const char *str, va_list args, int *count)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			if (ft_putchar_count(str[i], count) == -1)
				return (-1);
		}
		else
		{
			i++;
			if (ft_do_printf_sub2(str, args, count, i) == -1)
				return (-1);
		}
		if (str[i] != '\0')
			i++;
	}
	return (*count);
}

static int	ft_do_printf_sub2(const char *str, va_list args, int *count, int i)
{
	int	sub1_ret;

	sub1_ret = ft_do_printf_sub1(&str[i], args, count);
	if (sub1_ret == 0)
	{
		if (str[i] == '\0')
			return (-1);
		if (ft_putchar_count('%', count) == 0)
			return (-1);
		if (ft_putchar_count(str[i], count) == 0)
			return (-1);
	}
	else if (sub1_ret == -1)
		return (-1);
	return (1);
}

static int	ft_do_printf_sub1(const char *str, va_list args, int *count)
{
	if (*str == 'c')
		return (ft_putchar_count((char)va_arg(args, int), count));
	else if (*str == '%')
		return (ft_putchar_count('%', count));
	else if (*str == 's')
		return (ft_putstr_count(va_arg(args, char *), count));
	else if (*str == 'd' || *str == 'i')
		return (ft_putnbr_count(va_arg(args, int), count));
	else if (*str == 'p')
		return (ft_putaddress_count(va_arg(args, void *), count));
	else if (*str == 'x')
		return (ft_puthex_small_count(va_arg(args, unsigned int), count));
	else if (*str == 'X')
		return (ft_puthex_big_count(va_arg(args, unsigned int), count));
	else if (*str == 'u')
		return (ft_putuint_count(va_arg(args, unsigned int), count));
	else
		return (0);
}
