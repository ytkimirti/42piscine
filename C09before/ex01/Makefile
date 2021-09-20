FILES = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c srcs/ft_swap.c
OBJS = $(FILES:.c=.o)

FLAGS = -Wall -Wextra -Werror

# $@ the target
# $< first prerqusit
# $^ all of prerequsits
# $? prerequsits that changed
# $| order only prerequsits

.PHONY: all clean fclean re

all: libft.a

%.o: %.c
	gcc $(FLAGS) -c -o $@ $< -Iincludes

libft.a: ${OBJS}
	ar rcs libft.a $^

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f libft.a

re: fclean all
