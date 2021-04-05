#include <stdarg.h>
#include "ft_printf.h"

char	*parse_flag(t_list *a, char *s)
{
	if (*s == '-')
		a->minus = 1;
	else if (*s == '0')
		a->null = 1;
	while (*s == '-' || *s == '0')
	{
		if (*s == '-' && (a->null == 1))
		{
			a->null = 0;
			a->minus = 1;
		}
		s++;
	}
	return (s);
}

void	parse_sh_and_toch(t_list *a, char *s)
{
	if (*s == '*')
	{
		a->shir = va_arg(a->arg, int);
		s++;
	}
	if (*s > 48 && *s <= 57)
	{
		a->shir = ft_atoi(s);
		while (*s >= 48 && *s < 58)
			s++;
	}
	if (*s == '.')
	{
		a->dot = 1;
		if (*(++s) == '*')
			a->tochn = va_arg(a->arg, int);
		else
			a->tochn = ft_atoi(s);
	}
	if (a->tochn < 0)
	{
		a->tochn = 0;
		a->dot = 0;
	}
}

int		parse(char *s, t_list *a)
{
	int	i;

	i = 0;
	a->type = specifier(s);
	if (a->type == '-')
		return (-1);
	while (s[i] != a->type)
	{
		if (s[i] == '-' || s[i] == '.' || s[i] == 'd' ||
		(s[i] >= 48 && s[i] <= 57) || s[i] == '*')
			i++;
		else
			return (-1);
	}
	parse_sh_and_toch(a, parse_flag(a, s));
	specifierall(a);
	return (i);
}

int		cikl(char *c, t_list *a)
{
	int		b;
	int		i;

	i = 0;
	while (c[i])
	{
		while (c[i] == '%')
			if (((b = parse((&c[i + 1]), a)) == -1) || (a->kol == -1))
				return (-1);
			else if (c[i + b + 2])
			{
				i = i + b + 2;
				againstruct(a);
			}
			else
				return (1);
		againstruct(a);
		write(1, &c[i], 1);
		a->kol++;
		i++;
	}
	return (i);
}

int		ft_printf(const char *x, ...)
{
	int		i;
	char	*s;
	t_list	*a;
	t_list	c;

	a = &c;
	defstruct(a);
	va_start(a->arg, x);
	i = 0;
	s = (char *)x;
	if (cikl(s, a) == -1)
		return (-1);
	va_end(a->arg);
	return (a->kol);
}
