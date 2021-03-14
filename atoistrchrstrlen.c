/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoiStrchrStrlen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 23:05:45 by ydorene           #+#    #+#             */
/*   Updated: 2021/01/25 23:05:47 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strchr(const char *str, int ch)
{
	char *a;

	a = (char *)str;
	while (*a != '\0')
	{
		if (*a == ch)
			return (a);
		a++;
	}
	return (0);
}

size_t		ft_strlen(const char *a)
{
	size_t	i;

	if (!a)
		return (0);
	i = 0;
	while (a[i] != '\0')
		i++;
	return (i);
}

static int	wi(char *a, char b, char c)
{
	int i;

	i = 0;
	while (*a == b || *a == c)
	{
		i++;
		a++;
	}
	return (i);
}

static int	arb(char *a, int c)
{
	unsigned long long int i;

	i = 0;
	while (*a > 47 && *a < 58)
	{
		i = i * 10 + (*a - 48);
		a++;
	}
	if (i > 999999999999999999)
	{
		if (c == -1)
			return (0);
		else
			return (-1);
	}
	return (i * c);
}

int			ft_atoi(const char *x)
{
	int		i;
	int		c;
	char	*a;

	if (!x)
		return (0);
	c = 1;
	i = 0;
	a = (char *)x;
	if (wi(a, '+', '-') > 1)
		return (0);
	else if (wi(a, '+', '-') == 1)
	{
		if (*a == '-')
			c = -1;
		a++;
	}
	return (arb(a, c));
}
