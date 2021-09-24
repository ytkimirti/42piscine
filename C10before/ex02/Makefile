

SRCS = tail.c utils.c ft_atoi.c
OUT = ft_tail

RUNPARAMS = -c 5 a x x a  


OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean

all: ${OUT}

run: all
	-./${OUT} ${RUNPARAMS} ||:
	-tail ${RUNPARAMS} ||:

diff: all
	@./${OUT} ${RUNPARAMS} 2> .myout ||:
	@cat ${RUNPARAMS} 2> .origout ||:
	-@diff .myout .origout

%.o: %.c
	gcc ${FLAGS} -c -o $@ $^

${OUT}: ${OBJS}
	gcc ${FLAGS} $^ -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${OUT}
