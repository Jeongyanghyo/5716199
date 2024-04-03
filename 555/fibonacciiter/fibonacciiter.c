#include <stdio.h>

int fibonacci_iter(int n);

int main()
{
	int fibonacci = 0;
	fibonacci = fibonacci_iter(6);
	printf("Fibonacci 6=%d\n", fibonacci);
	return 0;
}

int fibonacci_iter(int n)
{
	int result = 0;
	int n_2 = 0,  n_1 = 1;
	
	if (n <= 1) return n;
	for (int i = 2; i <= n; i++)
	{

		result = n_1 + n_2;
		n_2 = n_1;
		n_1 = result;

	}
	return result;


}