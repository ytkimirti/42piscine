#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	n;
	
	printf("%s", "Enter a number: ");
	scanf("%d",&n);

	int *ptr;

	ptr = (int *)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
	{
		printf("Number %i is : ", i);
		scanf("%d",ptr + i);
	}
	
	for (int i = 0; i < n; i++)
	{
		printf("%i\n", ptr[i]);
	}
}
