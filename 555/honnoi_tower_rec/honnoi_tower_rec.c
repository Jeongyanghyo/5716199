#include <stdio.h>
#include <time.h>

void hanoi_tower(int n, char from, char tmp, char to)
{
	if (n == 1)printf("원판 1을 %c에서 %c로 옮긴다.\n", from, to);
	else {
		hanoi_tower(n - 1, from, to, tmp);
		printf("원판 %d를 %c에서 %c로 옮긴다\n", n, from, to);
		hanoi_tower((n - 1), tmp, from, to);

	}
}

int main()
{
	clock_t start, stop;
	long double duration;
	start = clock();
	hanoi_tower(4, 'A', 'B', 'C');
	stop = clock();
	duration = (double)(stop - start) / CLOCKS_PER_SEC;
	printf("time: %lf\n", duration);
	return 0;
}