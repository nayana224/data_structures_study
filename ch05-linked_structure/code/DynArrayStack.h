/*
코드 5.1 배열을 이용한 스택의 구현
*/
#include <stdio.h>
#include <stdlib.h>

int MAX_SIZE = 10;
Element* data = NULL;
int top; // 스택 상단 인덱스


void init_stack(void)
{
    data = (Element*)malloc(sizeof(Element) * MAX_SIZE);
    top = -1;
}


int is_full(void)
{
    if (top == (MAX_SIZE - 1))
        return 1; // 현재 top이 맨 위
    else
        return 0; // 여유 있음
}


void push(Element e)
{
    if (is_full()) {
        MAX_SIZE *= 2; // 오버플로 시, 용량 2배 늘림
        data = (Element*)realloc(data, sizeof(Element) * MAX_SIZE);
        printf("realloc(%d)\n", MAX_SIZE);
    }
    data[++top] = e;
}



void error(const char str[])
{
    printf("%s", str);
    exit(1);
}


int is_empty()
{
    if (top == -1)
        return 1; // 스택이 비어있음
    else
        return 0; // 스택이 비어있지 않음
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