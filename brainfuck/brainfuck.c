#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void brainfuck(char *str)
{
	int arr[2048] = {0};
	int brackets = 0;
	int *p; 
	p = arr;
	while (*str != 0)
	{
		if (*str == '+')
			(*p)++;
		else if (*str == '-')
			(*p)--;
		else if (*str == '>')
			p++;
		else if (*str == '<')
			p--;
		else if (*str == '.')
			ft_putchar(*p);
		else if (*str == '[' && *p == 0)
		{	
			brackets++;
			while (brackets != 0)
			{
				str++;
				if (*str == '[')
					brackets++;
				if (*str == ']')
					brackets--;
			}
		}
		else if (*str == ']' && *p != 0)
		{
			brackets++;
			while (brackets != 0)
			{
				str--;
				if (*str == '[')
					brackets--;
				if (*str == ']')
					brackets++;
			}
		}
		str++;
	}
}
