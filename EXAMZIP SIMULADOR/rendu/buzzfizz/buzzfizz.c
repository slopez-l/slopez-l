#include <unistd.h>

void	ft_print_nbr(int i)
{
	char	*digits;
	digits = "0123456789";
	if (i > 9)
		ft_print_nbr(i / 10);
	write(1, &digits[i % 10], 1);
}

int main(void)
{
	int	i;

	i = 1;
	while (i <= 100)
	{
		if ((i % 28) == 0)
			write(1, "buzzfizz", 8);
		else if ((i % 4) == 0)
		write(1, "buzz", 4);
		else if ((i % 7) == 0)
		write(1, "fizz", 4);
		else
			ft_print_nbr(i);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
