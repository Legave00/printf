/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:13:56 by ydorene           #+#    #+#             */
/*   Updated: 2021/01/27 16:13:57 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_char(char c, long long i)
{
	while (i)
	{
		write(1, &c, 1);
		i--;
	}
}

void	negd(t_list *a)
{
	if (a->minus == 1)
	{
		put_char('-', 1);
		put_char('0', a->nulls);
		write(1, a->string, a->razr);
		put_char(' ', a->space);
	}
	else
	{
		if (a->null == 1)
		{
			put_char('-', 1);
			put_char('0', a->space);
			write(1, a->string, a->razr);
		}
		else
		{
			put_char(' ', a->space);
			put_char('-', 1);
			put_char('0', a->nulls);
			write(1, a->string, a->razr);
		}
	}
}

void	posd(long long x, t_list *a)
{
	if (a->dot == 1 && a->tochn == 0 && x == 0)
	{
		a->string = NULL;
		a->kol--;
	}
	if (a->minus == 1)
	{
		put_char('0', a->nulls);
		write(1, a->string, a->razr);
		put_char(' ', a->space);
	}
	else
	{
		if (a->null == 1)
		{
			put_char('0', a->space);
			write(1, a->string, a->razr);
		}
		else
		{
			put_char(' ', a->space);
			put_char('0', a->nulls);
			write(1, a->string, a->razr);
		}
	}
}
