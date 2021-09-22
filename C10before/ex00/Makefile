FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean

all: ft_display_file

ft_display_file: display_file.c
	gcc ${FLAGS} $^ -o $@

clean:
	rm -f ft_display_file

fclean: clean
	rm -f ft_display_file
