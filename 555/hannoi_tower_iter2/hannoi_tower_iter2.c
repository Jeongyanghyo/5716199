#include <stdio.h>
#include <time.h>


// 스택을 표현하는 구조체 정의
#define MAX_SIZE 100
struct Stack {
    int arr[MAX_SIZE];
    int top;
};

// 스택 초기화 함수
void initStack(struct Stack* stack) {
    stack->top = -1;
}

// 스택이 비어있는지 확인하는 함수
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// 스택에 원소를 추가하는 함수
void push(struct Stack* stack, int value) {
    if (stack->top < MAX_SIZE - 1) {
        stack->arr[++stack->top] = value;
    }
}

// 스택에서 원소를 제거하고 반환하는 함수
int pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->arr[stack->top--];
    }
    return -1; // 스택이 비어있을 때
}

// 하노이 탑 문제를 해결하는 함수
void hannoitower_iter(int n, char from, char to, char tmp) {
    struct Stack s1, s2, s3; // 3개의 스택 생성
    initStack(&s1);
    initStack(&s2);
    initStack(&s3);

    int totalMoves = (1 << n) - 1; // 이동 횟수 계산

    // 초기 상태를 스택에 push
    for (int i = n; i >= 1; i--) {
        push(&s1, i);
    }

    // 이동 횟수에 따라 원판을 이동
    char temp;
    if (n % 2 == 0)
        temp = to, to = tmp, tmp = temp;

    for (int move = 1; move <= totalMoves; move++) {
       
        if (move % 3 == 1) {
            if (isEmpty(&s1)) {
                push(&s1, pop(&s2));
                printf("원판 %d를 %c에서 %c로 옮긴다.\n", s1.arr[s1.top], 'B', 'A');
            }
            else if (isEmpty(&s2)) {
                push(&s2, pop(&s1));
                printf("원판 %d를 %c에서 %c로 옮긴다.\n", s2.arr[s2.top], 'A', 'B');
            }
            else if (s1.arr[s1.top] > s2.arr[s2.top]) {
                push(&s1, pop(&s2));
                printf("원판 %d를 %c에서 %c로 옮긴다.\n", s1.arr[s1.top], 'B', 'A');
            }
            else {
                push(&s2, pop(&s1));
                printf("원판 %d를 %c에서 %c로 옮긴다.\n", s2.arr[s2.top], 'A', 'B');
            }
        }
        else if (move % 3 == 2) {
            if (isEmpty(&s1)) {
                push(&s1, pop(&s3));
                printf("원판 %d를 %c에서 %c로 옮긴다.\n", s1.arr[s1.top], 'C', 'A');
            }
            else if (isEmpty(&s3)) {
                push(&s3, pop(&s1));
                printf("원판 %d를 %c에서 %c로 옮긴다.\n", s3.arr[s3.top], 'A', 'C');
            }
            else if (s1.arr[s1.top] > s3.arr[s3.top]) {
                push(&s1, pop(&s3));
                printf("원판 %d를 %c에서 %c로 옮긴다.\n", s1.arr[s1.top], 'C', 'A');
            }
            else {
                push(&s3, pop(&s1));
                printf("원판 %d를 %c에서 %c로 옮긴다.\n", s3.arr[s3.top], 'A', 'C');
            }
        }
        else {
            if (isEmpty(&s2)) {
                push(&s2, pop(&s3));
                printf("원판 %d를 %c에서 %c로 옮긴다.\n", s2.arr[s2.top], 'C', 'B');
            }
            else if (isEmpty(&s3)) {
                push(&s3, pop(&s2));
                printf("원판 %d를 %c에서 %c로 옮긴다.\n", s3.arr[s3.top], 'B', 'C');
            }
            else if (s2.arr[s2.top] > s3.arr[s3.top]) {
                push(&s2, pop(&s3));
                printf("원판 %d를 %c에서 %c로 옮긴다.\n", s2.arr[s2.top], 'C', 'B');
            }
            else {
                push(&s3, pop(&s2));
                printf("원판 %d를 %c에서 %c로 옮긴다.\n", s3.arr[s3.top], 'B', 'C');
                
            }
        }
    }
}

int main(void) {
    clock_t start, stop;
    long double duration;
    start = clock();
    hannoitower_iter(4, 'A', 'C', 'B');
    stop = clock();
    duration = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("time: %lf\n", duration);
    return 0;
}
