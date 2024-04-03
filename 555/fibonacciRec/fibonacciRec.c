#include<stdio.h>

int fibonacci_rec(int n);

int  main()
{
	int fibonacci = 0;
	fibonacci = fibonacci_rec(6);
	printf("Fibonacci 6 = %d\n", fibonacci);
	return 0;

}

int fibonacci_rec(int n)
{
	printf("f(%d)\n", n);
	if (n == 0)return 0;
	else if (n == 1) return 1;
	else return (fibonacci_rec(n - 1) + fibonacci_rec(n - 2));

}