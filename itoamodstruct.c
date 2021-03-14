/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoamodstruct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 20:01:11 by ydorene           #+#    #+#             */
/*   Updated: 2021/01/27 20:01:17 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			defstruct(t_list *a)
{
	a->dot = 0;
	a->minus = 0;
	a->null = 0;
	a->shir = 0;
	a->tochn = 0;
	a->type = '0';
	a->kol = 0;
	a->razr = 0;
	a->space = 0;
	a->nulls = 0;
	a->sigh = 0;
	a->string = NULL;
}

void			againstruct(t_list *a)
{
	a->dot = 0;
	a->minus = 0;
	a->null = 0;
	a->shir = 0;
	a->tochn = 0;
	a->type = '0';
	a->razr = 0;
	a->space = 0;
	a->nulls = 0;
	a->sigh = 0;
	a->string = NULL;
}

long int		modul(long long n)
{
	long long a;

	a = n;
	if (n >= 0)
		return (a);
	else
		return (-a);
}

char			*ft_itoa(long long n)
{
	static char		a[50];
	long long		i;
	long long		s;

	i = 1;
	s = modul(n);
	while (s > 9)
	{
		i++;
		s = s / 10;
	}
	s = modul(n);
	a[i--] = '\0';
	while (s)
	{
		a[i--] = s % 10 + 48;
		s = s / 10;
	}
	if (n < 0)
		a[0] = '-';
	return (a);
}
