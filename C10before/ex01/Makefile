

SRCS = cat.c
OUT = ft_cat
OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean

all: ${OUT}

%.o: %.c
	gcc ${FLAGS} -c -o $@ $^

${OUT}: ${OBJS}
	gcc ${FLAGS} $^ -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${OUT}
