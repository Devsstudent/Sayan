#include <unistd.h>


// setup number*

int	*number(int n, int *numbers)
{
	int increment;
	int zero_to_nine;
	zero_to_nine = 48;
	increment = 0;
	while (increment < n)
	{
		numbers[increment] = zero_to_nine;
		zero_to_nine++;
		increment++;
	}
	return numbers;
}


// increment number

void	increment(int size, int *number)
{
	int cursor;
	int round;
	cursor = size - 1;
	round = 0;
	number[cursor]++;
	while (cursor > 0)
	{
		if (number[cursor] > 57 - round)
		{
			number[cursor - 1]++;
			if (number[cursor - 1] < 57 - round)
			{
				number[cursor] = number[cursor - 1] + 1;
			}
			else
			{
				number[cursor] = 57 - round;
			}
		}
		round++;
		cursor--;
	}
}

// check number

int	check(int size, int *array)
{
	int round;
	int counter_from_n;
	counter_from_n = size - 1;
	round = 0;
	if(array[counter_from_n] == 57)
	{
		while (array[counter_from_n] == 57 - round && counter_from_n >= 0)
		{
			counter_from_n--;
			round++;
		}
		if (round == size)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	return 0;
}

// display number 

void	display(int *number, int size)
{
	int browser;
	char space;
	char comma;
	space = ' ';
	comma = ',';
	browser = 0;
	while (browser < size)
	{
		write(1, &number[browser], 1);
		browser++;
	}
	if (check(size, number) == 0)
	{
		write(1, &comma, 1);
		write(1, &space, 1);
	}
	else
	{
		return;
	}
}

void	ft_print_combn(int n)
{
	int numbers[n];
	number(n, numbers);
	display(numbers, n);
	while (check(n, numbers) == 0)
	{
		increment(n, numbers);
		display(numbers, n);
	}
	return;
}
