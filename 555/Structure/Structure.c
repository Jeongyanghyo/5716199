#include <stdio.h>
#include <string.h>

struct student {
	int age;
	char name[30];

};
int main() {
	struct student s1, s2;
	s1.age = 21;
	strncpy_s(s1.name, 30, "학생이름", 20);

	s2.age = s1.age;
	strncpy_s(s2.name, 30, s1.name, 20);

	printf("s1의 나이는 %d이고 이름은 \"%s\" 입니다. \n", s1.age, s1.name);
	printf("s2 나이는 %d이고 이름은 \"%s\" 입니다. \n", s2.age, s2.name);

}