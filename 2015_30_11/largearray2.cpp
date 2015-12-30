#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void array(int*, int);
void main()
{
	int n, i;
	printf("\nEnter no .of elements : ");
	scanf("%d", &n);
	int *a = (int*)malloc(sizeof(int)*n);
	
	
	printf("\nenter the elements elements : ");
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	array(a, n);
	
	
	_getch();

}


void array(int *a, int n)
{
	int sum = 0, index = 0;

	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		if (sum + a[i] > 0)
		{
			if (sum == 0)
				index = i;
			sum += a[i];
		}
		else
			sum = 0;
		if (ans < sum){
			ans = sum;
		}
		//ans = ans > sum ? ans : sum;
	}
	printf("The maximum subarray is :\n ");
	while (sum != ans)
	{
		sum += a[index];
		printf("%d\t", a[index]);
		index++;
	}



}

