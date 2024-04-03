#include <stdio.h>

int main()
{
	int i = 10, j = 12, k = 13, l = 19, m = 21;

	int intArray[5][10] = { {10, 12, 13, 19, 21, 33},
							  {13, 45, 56} };

	printf("intArray의 크기는 %d 입니다.\n", sizeof(intArray));
	printf("정수형 변수의 크기는 %d입니다.\n", sizeof(i));
	printf("intArray 배열 변수에는 %d개의 정수를 저장할 수 있습니다.\n", sizeof(intArray) / sizeof(int));



	printf("변수 j의 값은 %d입니다.\n", j);

	i = 11;
	j = k;

	printf("배열 intArray의 [1][3]번째 값은 %d입니다.\n", intArray[1][3]);
	intArray[1][3] = 11;
	printf("배열 intArray의 [1][3]번째 값은 %d입니다.\n", intArray[1][3]);

	/*intArray[1] = 11;
	intArray[3] = k;*/

	m = intArray[4];

	m = intArray[5];  //사용불가 
	

}