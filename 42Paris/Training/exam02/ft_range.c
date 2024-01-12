#include <stdlib.h>

int ft_counter(int start, int end)
{
	int counter = 0;
	if(start < end)
	{
		while(start <= end)
		{
			start++;
			counter++;
		}
	}
	else if (start > end)
	{
		while(end <= start)
		{
			end++;
			counter++;
		}
	}
	else 
		return (1);
	return(counter);
}
int *ft_range(int start, int end)
{
	int *array;
	int i = 0;
	int count;
	count = ft_counter(start,end);
	__builtin_printf("counter = %d\n",count);
	array = malloc(sizeof(int) * count);
	if(!array)
		return(0);
	
	if (start < end)
	{
		while(start <= end)
			array[i++] = start++;
	}
	else if (end < start)
	{
		while(end <= start)
			array[i++] = start--;
	}
	else
		array[i] = start;
	return(array);
}

int main(void)
{
	int *array = ft_range(0, -3);
	int i = 0;
	while(i < ft_counter(0, -3))
	{
		__builtin_printf("%d\n",array[i]);
		i++;
	}
}