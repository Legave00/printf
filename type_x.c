/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 19:05:09 by ydorene           #+#    #+#             */
/*   Updated: 2021/01/27 19:05:11 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			kolich(unsigned long x, t_list *a)
{
	int i;

	i = 0;
	if (x == 0 && a->dot == 1 && a->tochn == 0)
		i = 0;
	else if (x == 0)
		i = 1;
	while (x)
	{
		x = x / 16;
		i++;
	}
	a->razr = i;
}

int				print_x(long long x, t_list *a, char *s)
{
	long long		i;
	char			*b;
	int				c;

	c = a->razr;
	if (!(b = malloc(c * sizeof(char) + 1)))
		return ((a->kol = -1));
	b[c] = '\0';
	if (x == 0 && (a->tochn > 0 || a->dot == 0))
	{
		write(1, "0", 1);
		a->kol++;
		return (a->kol);
	}
	while (x)
	{
		i = x % 16;
		x = x / 16;
		b[c - 1] = s[i];
		c--;
		a->kol++;
	}
	write(1, b, a->razr);
	free(b);
	return (a->kol);
}

void			type_x(unsigned long int x, t_list *a, char *s)
{
	kolich(x, a);
	nulls(a);
	space(a);
	if (a->minus == 1)
	{
		put_char('0', a->nulls);
		print_x(x, a, s);
		put_char(' ', a->space);
	}
	else if (a->null == 1)
	{
		put_char('0', a->space);
		print_x(x, a, s);
	}
	else
	{
		put_char(' ', a->space);
		put_char('0', a->nulls);
		print_x(x, a, s);
	}
	a->kol = a->kol + a->space + a->nulls;
}
