#include "ft_printf.h"

void	print_s(long long x, t_list *a)
{
	if (a->dot == 1 && a->tochn == 0 && x == 0)
		a->string = NULL;
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

void	space_s(t_list *a)
{
	if (a->tochn < a->razr && a->dot == 1)
		a->nulls = a->tochn;
	else
		a->nulls = a->razr;
	if (a->shir > a->nulls)
		a->space = a->shir - a->nulls;
	else
		a->space = 0;
}

void	type_s(char *s, t_list *a)
{
	if (!s)
	{
		s = "(null)";
		a->nulls = 6;
	}
	a->razr = ft_strlen(s);
	space_s(a);
	if (a->minus == 1)
	{
		write(1, s, a->nulls);
		put_char(' ', a->space);
	}
	else
	{
		put_char(' ', a->space);
		write(1, s, a->nulls);
	}
	a->kol = a->kol + a->nulls + a->space;
}
