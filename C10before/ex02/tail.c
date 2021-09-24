#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

typedef struct s_c
{
	char		c;
	struct s_c	*next;
}t_c;

t_c	*dummy;
t_c	*head;
t_c	*tail;
int	an_error_occured;
int	multiple_files;
int	num_succesfull;

void	ft_putstr(char *str);

int		ft_atoi(char *str);

int		ft_err(char *errormsg);

int		string_equals(char *a, char *b);

t_c	*add_char(char c, t_c *tail)
{
	t_c	*new;

	new = (t_c *)malloc(sizeof(t_c));
	new->c = c;
	new->next = 0;
	tail->next = new;
	return (new);
}

void	print_list(t_c *h)
{
	while (h != 0)
	{
		write(1, &(h->c), 1);
		h = h->next;
	}
}

void rotate_list()
{
	t_c *new_head;
	
	if (head == 0 || head->next == 0)
		return ;
	new_head = head->next;
	head->next = 0;
	tail->next = head;
	head = new_head;
	tail = tail->next;
}

void	linked(char c, int	add_new)
{
	if (add_new)
	{
		if (dummy != 0)
		{
			head = add_char(c, dummy);
			tail = head;
			dummy = 0;
		}
		else
		{
			tail = add_char(c, tail);
		}
	}
	else
	{
		head->c = c;
		rotate_list();
	}
	/*write(1, "List: ", 6);*/
	/*print_list(head);*/
	/*write(1, "\n", 1);*/
}

void	free_list()
{
	while (head != 0)
	{
		t_c	*buff;
		buff = head;
		head = head->next;
		free(buff);
	}
}

void	print_header(char *filename)
{
	ft_putstr("==> ");
	ft_putstr(filename);
	ft_putstr(" <==\n");
}

int	ft_tail(char *filename, int len, int is_first_file)
{
	int		file;
	int		numbytes;
	char	c;
	int		i;

	head = malloc(sizeof(t_c));
	dummy = head;
	tail = head;
	file = 0;
	if (filename != 0)
		file = open(filename, O_RDONLY);
	if (file == -1)
		return (ft_err(filename));
	if (!is_first_file)
		write(1, "\n", 1);
	i = 0;
	while (1)
	{
		numbytes = read(file, &c, 1);
		if (numbytes == -1)
			return (ft_err(filename));
		if (numbytes == 0)
			break ;
		linked(c, i < len);
		i++;
	}
	if (file != 0 && close(file) != 0)
		return (ft_err(filename));
	if (multiple_files)
		print_header(filename);
	print_list(head);
	free_list();
	return (1);
}


int	main(int argc, char *argv[])
{
	int	i;
	int	an_error_occured;
	int	len;

	multiple_files = argc > 4;
	if (argc <= 2)
		return (1);
	if (!string_equals(argv[1], "-c"))
		return (1);
	len = ft_atoi(argv[2]);
	if (len <= 0)
		return (0);
	if (argc == 3)
		return (!ft_tail(0, len, 1));
	i = 3;
	an_error_occured = 0;
	while (i < argc)
	{
		if(!ft_tail(argv[i], len, i == 3))
			an_error_occured = 1;
		i++;
	}
	return (an_error_occured);
}
