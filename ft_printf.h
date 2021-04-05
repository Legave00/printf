#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct	s_list
{
	char		type;
	int			minus;
	int			null;
	int			shir;
	int			tochn;
	int			dot;
	int			kol;
	va_list		arg;
	int			razr;
	int			nulls;
	int			space;
	int			sigh;
	char		*string;
}				t_list;

void			kolich(unsigned long x, t_list *a);
void			type_x(unsigned long int x, t_list *a, char *s);
void			type_p(unsigned long long x, t_list *a, char *s);
void			type_c(int i, t_list *a);
void			type_perc(t_list *a);
char			specifier(char *s);
void			space(t_list *a);
void			nulls(t_list *a);
void			kol(long long i, t_list *b);
int				type_u(unsigned int x, t_list *a);
void			put_char(char c, long long i);
void			posd(long long x, t_list *a);
void			negd(t_list *a);
int				type_d(long x, t_list *a);
void			type_s(char *s, t_list *a);
char			*zap(long long n, long long i, char *a);
char			*ft_itoa(long long n);
void			defstruct(t_list *a);
void			againstruct(t_list *a);
long int		modul(long long n);
int				ft_printf(const char *s, ...);
int				ft_atoi(const char *x);
size_t			ft_strlen(const char *a);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(const char *s1, const char *s2);
void			*ft_calloc(size_t number, size_t size);
char			*ft_strchr(const char *str, int ch);
char			*ft_strjoin(char const *s1, char const *s2);
void			specifierall(t_list *a);
#endif
