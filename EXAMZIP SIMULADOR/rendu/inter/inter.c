#include <unistd.h>

int	ft_single(char *str, char c, int i)
{
	int	j;

	j = 0;
	while (str[j] != '\0' && j < i)
	{
		if (str[j] == c)
			return (1);
		j++;
	}
	return (0);
}

int	ft_other(char *str, char c)
{
	int	j;

	j = 0;
	while (str[j] != '\0')
	{
		if (str[j] == c)
			return (1);
		j++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 3)
	{
		while (argv[1][i] != '\0')
		{
			if ((ft_single(argv[1], argv[1][i], i) == 0)
			&& (ft_other(argv[1],argv[2][i]) == 1))
				write(1, &argv[1][i], 1);
			
		}
	}
	write(1, "\n", 1);
	return (0);
}
