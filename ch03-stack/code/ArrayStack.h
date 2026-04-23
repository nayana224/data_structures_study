/*
코드 3.1 배열을 이용한 스택의 구현
*/
#include <stdio.h>
#include <stdlib.h>
// #define MAX_SIZE 100
// typedef int Element; // 앞으로 Element형은 int형
Element data[MAX_SIZE];
int top; // 스택 상단 인덱스

void error(const char str[])
{
    printf("%s", str);
}

void init_stack(void)
{
    top = -1;
}

int is_empty(void)
{
    if (top == -1)
        return 1; // 스택이 비어있음
    else
        return 0; // 스택이 비어있지 않음
}

int is_full()
{
    if (top == (MAX_SIZE - 1)) 
        return 1; // 현재 top이 맨 위
    else
        return 0; // 여유 있음
}

void push(Element e)
{
    if (is_full())
    {
        error("Overflow Error");
    }
    else
    {
        // top을 먼저 증가시키고, 그 위치에 e 복사
        data[++top] = e;
    }
}

Element pop(void)
{
    if (is_empty())
    {
        error("Underflow Error");
    }
    else
    {
        // top에 있는 data 리턴 후 top-1
        return data[top--];
    }
}

Element peek(void)
{
    if (is_empty())
    {
        error("Underflow Error");
    }
    else
    {
        // top에 있는 data 리턴만 함
        return data[top];
    }
}