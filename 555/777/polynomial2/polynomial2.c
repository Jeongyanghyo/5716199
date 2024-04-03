#include <stdio.h>
#define MAX_TERMS 101

struct{
	float coef;
	int expon;

}terms[MAX_TERMS] = { {8.0, 3},{7.0, 1 }, {1.0, 0},
					{10.0, 3}, { 3.0, 2 }, {1.0, 0 } };

int avail = 6;

void print_poly(int s, int e);
void poly_add2(int As, int Ae, int Bs, int Be, int *Csp, int *Cep);

main() {
	int Cs, Ce;
	printf("A=");
	print_poly(0, 2);
	printf("B=");
	print_poly(3, 5);

	poly_add2(0,2,3,5, &Cs, &Ce);
	printf("A+B=");
	print_poly(Cs, Ce);

}

void attach(float coef, int expon) {
	if (avail > MAX_TERMS) {
		fprintf(stderr, "Too long terms\n");
		exit(1);

	}
	terms[avail].coef = coef;
	terms[avail].expon = expon;
	avail++;
}


void poly_add2(int As, int Ae, int Bs, int Be, int *Csp, int *Cep) {
	/**Csp = avail;*/
	int C_start = avail;
	while ((As <= Ae) && (Bs <= Be)) {
		if (terms[As].expon > terms[Bs].expon) {
			//terms[/**Csp*/C_start].expon = terms[As].expon;
			//terms[/**Csp*/C_start].coef = terms[As].coef;
			attach(terms[As].coef, terms[As].expon);
			As++; //As = As + 1;
			/*(*Csp)*//*C_start++;*/
			//printf("copy from A to C");
		}
		else if (terms[As].expon == terms[Bs].expon) {
			//terms[/**Csp*/C_start].expon = terms[As].expon;
			//terms[/**Csp*/C_start].coef = terms[As].coef + terms[Bs].coef;
			attach(terms[As].coef+ terms[Bs].coef, terms[As].expon);
			As++; //As = As + 1;
			Bs++; //Bs = Bs + 1;
			/*(*Csp)*//*C_start++;*/
			//printf("copy from A+B to C");

		}
		else {
			//terms[/**Csp*/C_start].expon = terms[Bs].expon;
			//terms[/**Csp*/C_start].coef = terms[Bs].coef;
			attach(terms[Bs].coef, terms[Bs].expon);
			Bs++; //Bs = Bs + 1;
			/*(*Csp)*//*C_start++;*/
			//printf("copy from B to C");

		}
	}
	for (; As <= Ae; As++) {
		//terms[/**Csp*/C_start].expon = terms[As].expon;
		//terms[/**Csp*/C_start].coef = terms[As].coef;
		attach(terms[As].coef, terms[As].expon);
		As++; //As = As + 1;
		/*(*Csp)*//*C_start++;*/
	}
	for (; Bs <= Be; Bs++) {
		//terms[/**Csp*/C_start].expon = terms[Bs].expon;
		//terms[/**Csp*/C_start].coef = terms[Bs].coef;
		attach(terms[Bs].coef, terms[Bs].expon);
		Bs++; //As = As + 1;
		/*(*Csp)*//*C_start++;*/
	}
	/**Csp = avail;
	*Cep = C_start - 1;
	avail = C_start;*/ //attach를 안썼을때
	*Csp = C_start;
	*Cep = avail - 1;
}

void print_poly(int s, int e) {
	for (int i = s; i < e; i++) {
		printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
	}
	printf("%3.1f\n ", terms[e].coef);
}