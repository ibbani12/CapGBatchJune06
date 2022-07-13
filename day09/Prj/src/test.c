#include <stdio.h>

int main()
{
	extern int SIZE;
	int a[SIZE];

	for(int i=0;i<SIZE;i++)
	{
		a[i] = (i+1);
	}

	printf("\nArrays are\n");
	for(int i=0;i<SIZE;i++)
	{
		printf("\n%d",a[i]);
	}	
	
	return 0;
}