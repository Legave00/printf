/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shir_tochn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:10:29 by ydorene           #+#    #+#             */
/*   Updated: 2021/01/27 19:54:08 by ydorene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	kol(long long i, t_list *b)
{
	int		a;
	char	*tmp;

	a = 0;
	if (i == 0)
	{
		b->razr = 1;
		b->string = "0";
	}
	else
	{
		if (i < 0)
			b->sigh = 1;
		tmp = ft_itoa(modul(i));
		b->string = tmp;
		i = modul(i);
		while (i)
		{
			i = i / 10;
			a++;
		}
		b->razr = a;
	}
}

void	nulls(t_list *a)
{
	int b;

	b = a->razr;
	if (a->dot == 1)
	{
		if (b < a->tochn)
			b = a->tochn - b;
		else
			b = 0;
	}
	else
		b = 0;
	a->nulls = b;
}

void	space(t_list *a)
{
	int kl_sp;

	kl_sp = 0;
	if (a->shir >= 0)
	{
		if (((a->nulls + a->razr + a->sigh) <= a->shir))
			kl_sp = a->shir - a->nulls - a->razr - a->sigh;
	}
	a->space = kl_sp;
}
