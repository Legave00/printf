/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 15:57:01 by ydorene           #+#    #+#             */
/*   Updated: 2021/01/27 15:57:07 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_perc(t_list *a)
{
	if (a->shir > 1)
		a->space = a->shir - 1;
	a->kol = a->kol + a->space;
	if (a->minus == 1)
	{
		write(1, "%", 1);
		put_char(' ', a->space);
	}
	else if (a->null == 1)
	{
		put_char('0', a->space);
		write(1, "%", 1);
	}
	else
	{
		put_char(' ', a->space);
		write(1, "%", 1);
	}
	a->kol++;
}

void	type_c(int i, t_list *a)
{
	char	c;

	c = i;
	if (a->shir > 1)
		a->space = a->shir - 1;
	a->kol = a->kol + a->space + 1;
	if (a->minus == 1)
	{
		write(1, &c, 1);
		put_char(' ', a->space);
	}
	else
	{
		put_char(' ', a->space);
		write(1, &c, 1);
	}
}
