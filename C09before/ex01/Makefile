FILES = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c srcs/ft_swap.c
OBJS = $(FILES:.c=.o)

FLAGS = -Wall -Wextra -Werror

TEST = $(wildcard */*.c)


# $@ the target
# $< first prerqusit
# $^ all of prerequsits
# $? prerequsits that changed
# $| order only prerequsits

.PHONY: all clean fclean re

all: libft.a

test:
	echo $(TEST)

%.o: %.c
	gcc $(FLAGS) -c -o $@ $< -Iincludes

libft.a: ${OBJS}
	ar rcs libft.a $^

clean:
	rm -f */*.o

fclean:
	rm -f */*.o
	rm -f libft.a

re: fclean all
