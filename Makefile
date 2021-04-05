NAME	= libftprintf.a
SRC		= ft_printf.c type_d.c specifierall.c atoistrchrstrlen.c itoamodstruct.c print_d.c shir_tochn.c type_u.c type_s.c type_c.c type_x.c type_p.c

OBJ		= ${SRC:.c=.o}
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
HEADER  = -I ft_printf.h

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

${NAME}: ${OBJ}
	ar rc ${NAME} ${OBJ}
	ranlib ${NAME}

all:  ${NAME}

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY:	all clean fclean re
















