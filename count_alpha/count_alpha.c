#include <unistd.h>
#include <stdio.h>

char	lowercase(char c);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		count(char *str, char c)
{
	int i;
	int counter;

	counter = 0;
	i = 0;
	while (str[i] != 0)
	{
		if (lowercase(str[i]) == lowercase(c))
			counter++;
		i++;
	}
	return (counter);
}

int		check(char *str, char c, int i)
{
	int j = 0;
	while (j < i)
	{
		if (lowercase(str[j]) == lowercase(c)) 
			return (0);
		j++;
	}
	return (1);
}

int		is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else 
		return (0);
}

char	lowercase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else 
		return c;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	int i = 0;
	char tab[32];
	int j = 0;
	if (argv[1][0] == 0)
	{
		printf("\n");
		return (0);
	}
	while (argv[1][i] != 0)
	{
		if (check(argv[1], argv[1][i], i) && is_alpha(argv[1][i]))
		{
			tab[j] = lowercase(argv[1][i]);
			j++;
		}
		i++;
	}
	tab[j] = '\0';
	j = 0;
	while (tab[j] != '\0')
	{
		if (tab[j + 1] == '\0')
		{
			printf("%d%c", count(argv[1], tab[j]), tab[j]);
			printf("\n");
			return (0);
		}
		printf("%d%c, ", count(argv[1], tab[j]), tab[j]);
		j++;
	}
	return (0);
}














