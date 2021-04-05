#include "ft_printf.h"

int		type_d(long x, t_list *a)
{
	if (x > 2147483647 || x < -2147483648)
		return (a->kol = -1);
	if (a->dot == 1 && a->shir != 0 && a->tochn == 0 && x == 0)
		a->shir++;
	kol(x, a);
	nulls(a);
	space(a);
	if (a->sigh == 0)
		posd(x, a);
	else
	{
		negd(a);
		a->kol++;
	}
	return ((a->kol = a->kol + a->nulls + a->razr + a->space));
}
