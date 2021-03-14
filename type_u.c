/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:11:45 by ydorene           #+#    #+#             */
/*   Updated: 2021/01/27 18:30:21 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_u(long long x, t_list *a)
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

int		type_u(unsigned int x, t_list *a)
{
	if (a->dot == 1 && a->shir != 0 && a->tochn == 0 && x == 0)
		a->shir++;
	kol(x, a);
	nulls(a);
	space(a);
	if (x > 4294967295)
		a->kol = -1;
	else if (x < 0)
		x = x + 4294967295;
	print_u(x, a);
	return ((a->kol = a->kol + a->nulls + a->razr + a->space));
}
