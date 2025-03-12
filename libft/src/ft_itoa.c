/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srussame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:54:03 by srussame          #+#    #+#             */
/*   Updated: 2024/08/27 16:54:03 by srussame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_assignnum(char *s, int n);
static int	ft_countdigit(int n);
static int	ft_power(int num, int power);

char	*ft_itoa(int n)
{
	int		d;
	char	*temp;

	if (n < -2147483647)
		return (ft_strdup("-2147483648"));
	d = ft_countdigit(n);
	if (n >= 0)
		temp = (char *)malloc(d + 1);
	else
		temp = (char *)malloc(d + 2);
	if (!temp)
		return (0);
	if (n < 0)
	{
		temp[0] = '-';
		ft_assignnum(&temp[1], (n * -1));
	}
	else
		ft_assignnum(&temp[0], n);
	return (temp);
}

static void	ft_assignnum(char *s, int n)
{
	int	m;
	int	i;

	m = ft_countdigit(n) - 1;
	i = 0;
	while (m >= 0)
	{
		s[i] = (n / ft_power(10, m)) + 48;
		n = n % ft_power(10, m);
		m--;
		i++;
	}
	s[i] = '\0';
}

static int	ft_power(int num, int power)
{
	int	res;

	if (num == 0)
		return (0);
	if (power == 0)
		return (1);
	res = num;
	while (power > 1)
	{
		res *= num;
		power--;
	}
	return (res);
}

static int	ft_countdigit(int n)
{
	int	i;

	i = 1;
	while (n / 10 != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}
