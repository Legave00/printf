#include "ft_printf.h"

char	specifier(char *s)
{
	char	*a;
	int		i;
	int		b;

	i = 0;
	b = 0;
	a = "cspdiuxX%";
	while (s[i])
	{
		while (a[b])
		{
			if (s[i] == a[b])
				return (a[b]);
			else
				b++;
		}
		i++;
		b = 0;
	}
	return ('-');
}

void	specifiers(t_list *a)
{
	char	*s;

	s = NULL;
	if (a->type == 'd' || a->type == 'i')
		type_d(va_arg(a->arg, int), a);
	else if (a->type == 'c')
		type_c(va_arg(a->arg, int), a);
	else if (a->type == '%')
		type_perc(a);
	else if (a->type == 'u')
		type_u(va_arg(a->arg, unsigned int), a);
	else if (a->type == 's')
		type_s((s = va_arg(a->arg, char*)), a);
	else if (a->type == 'x')
		type_x(va_arg(a->arg, unsigned int), a, "0123456789abcdef");
	else if (a->type == 'X')
		type_x(va_arg(a->arg, unsigned int), a, "0123456789ABCDEF");
	else if (a->type == 'p')
		type_p(va_arg(a->arg, unsigned long long int), a, "0123456789abcdef");
}

void	specifierall(t_list *a)
{
	if (a->shir < 0)
	{
		a->shir = modul(a->shir);
		a->minus = 1;
	}
	if (a->shir == 0)
	{
		a->minus = 0;
		a->null = 0;
	}
	if (a->dot == 1 && a->type != '%')
		a->null = 0;
	specifiers(a);
}
