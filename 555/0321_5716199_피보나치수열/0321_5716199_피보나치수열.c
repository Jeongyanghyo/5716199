#include <stdio.h>

int fib(int n)
{
	if (n == 0) return 0;
	if (n == 0) return 1;
	return(fib(n - 1) + fib(n - 2));

}

int fib_iter(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;

	int pp = 0;
    int p = 1;
	int result = 0;

	for (int i = 2; i <= n; i++)
	{
		result = p + pp;
		pp = p;
		p = result;
	}
	return result;
}

int main(void)
{
	double result_iter = fib_iter(10);
	printf("fibonacci_iter: %lf", result_iter);
	return 0;
}

