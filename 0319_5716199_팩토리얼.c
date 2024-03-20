#include <stdio.h>
#include <time.h>

double factorial_iter(int n)         //팩토리얼 반복적구현 함수 factorial_iter 정의
{
	int k;
	double v = 1;                 
	for (k = n; k > 0; k--)     
		v = v * k;
	return(v);

}
double factorial_rec(int n)     //팩토리얼 재귀적구현 함수 factorial_rec 정의
{
	if (n <= 1)return(1);
	else return (n * factorial_rec(n - 1));
}

int main(void)
{
	clock_t start, stop;                    
	clock_t start1, stop2;
	double duration;
	double duration3;
	start = clock();
	double result_iter = factorial_iter(20);                // 팩토리얼 반복적구현 factirial_irer함수에 n값 20 입력
	printf("Factorial Iterative Result: %lf\n", result_iter);
	stop = clock();
	duration = (double)(stop - start) / CLOCKS_PER_SEC;
	printf("time: %f\n", duration);
	start1 = clock();
	double result_rec = factorial_rec(20);                 //팩토리얼 재귀적구현 factorial_rec에 n값 20 입력
	printf("Factorial Iterative Result: %lf\n", result_rec);
	stop2 = clock();
	duration3 = (double)(stop2 - start1) / CLOCKS_PER_SEC;
	printf("time: %f\n", duration3);
	return 0;
}
// 반복적표현코드가 재귀적표현보다 더 많은 연산시간이 필요하다.