#include "ft_printf.h"

int			print_p(unsigned long long x, t_list *a, char *s)
{
	long long		i;
	char			*b;
	int				c;

	c = a->razr;
	if (!(b = malloc(c * sizeof(char) + 1)))
		return ((a->kol = -1));
	if (x == 0 && (a->tochn > 0 || a->dot == 0))
	{
		(a->dot == 0) ? write(1, "0x0", 3) : write(1, "0", 1);
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
	(a->nulls > 0) ? 0 : write(1, "0x", 2);
	write(1, b, a->razr);
	free(b);
	return ((a->kol));
}

void		space_p(t_list *a)
{
	int kl_sp;

	kl_sp = 0;
	if (a->shir >= 0)
	{
		if (((a->nulls + a->razr + a->sigh + 2) <= a->shir))
			kl_sp = a->shir - a->nulls - a->razr - a->sigh - 2;
	}
	a->space = kl_sp;
}

void		type_p(unsigned long long x, t_list *a, char *s)
{
	kolich(x, a);
	nulls(a);
	space_p(a);
	if (a->minus == 1)
	{
		put_char('0', a->nulls);
		print_p(x, a, s);
		put_char(' ', a->space);
	}
	else if (a->null == 1)
	{
		put_char('0', a->space);
		print_p(x, a, s);
	}
	else
	{
		(a->nulls > 0) ? write(1, "0x", 2) : 0;
		put_char(' ', a->space);
		put_char('0', a->nulls);
		print_p(x, a, s);
	}
	a->kol = a->kol + a->space + a->nulls + 2;
}
