#include <stdio.h>

// 반복적인 방법으로 하노이 탑 문제를 해결하는 함수
void hannoitower_iter(int n, char from, char to, char tmp) {
    while (n > 0) {
        if (n == 1) {
            printf("원판 1을 %c에서 %c로 옮긴다.\n", from, to);
            n--;
        }
        else {
            printf("원판 %d를 %c에서 %c로 옮긴다.\n", n, from, tmp);
            n -- ;
            int temp = from;
            from = tmp;
            tmp = temp;
        }
    }
}

int main(void) {
    hannoitower_iter(4, 'A', 'C', 'B');
    return 0;
}
