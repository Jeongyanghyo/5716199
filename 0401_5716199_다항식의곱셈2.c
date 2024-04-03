#include <stdio.h>
#define MAX_DEGREE 101

typedef struct {
	int degree;
	float coef[MAX_DEGREE];
}polynomial;

polynomial a = { 6, {7, 0, 0, 5, 9, 0, 1} };
polynomial b = { 3, {5, 2, 1, 10} };

void print_polynomial(polynomial p);
polynomial mult_polynomial(polynomial A, polynomial B);


polynomial mult_polynomial(polynomial A, polynomial B) {
	polynomial C;

	C.degree = A.degree + B.degree;

	for (int i = 0; i <= C.degree; i++) {
		C.coef[i] = 0.0;
	}

	for (int i = 0; i <= A.degree; i++) {
		for (int j = 0; j <= B.degree; j++) {
			C.coef[i + j] += A.coef[i] * B.coef[j];

		}
	}
	return C;

}

void print_polynomial(polynomial p) {
	for (int i = p.degree; i > 0; i--)
		printf(" %3.1fx^%d  +", p.coef[p.degree - i], i);
	printf(" %3.1fx\n", p.coef[p.degree], p.degree);
}

int main(void) {
	polynomial a = { 3,{4, 3, 2, 1} };
	polynomial b = { 2, {3, 2, 8} };
	polynomial c;

	print_polynomial(a);
	print_polynomial(b);

	c = mult_polynomial(a, b);
	printf("-----------------------------------------------------------------\n");
	print_polynomial(c);

	return 0;
}