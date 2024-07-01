NAME = libftprintf.a

SRC = 	ft_printf.c 	\
		ft_putstr_pf.c	\
		ft_putnbr_pf.c 	\
		ft_putptr_pf.c 	\
		ft_putchar_pf.c \
		ft_putunbr_pf.c \
		ft_puthexa_pf.c \

OBJ = $(SRC:%.c=%.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):$(OBJ)
	ar rcs $(NAME) $(OBJ) 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
