#include <stdio.h>
#include <stdlib.h>

// 자기 참조 구조체
// 노드 1개
typedef struct Node {
    Element data;
    struct Node* link;
} Node;
Node* top = NULL;

Node* alloc_node(Element e)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = e;
    p->link = NULL;
    return p;
}

Element free_node(Node* p)
{
    Element e = p->data; // 데이터 복사
    free(p); // 동적 해제 
    return e; // 데이터 반환
}

void error(const char* str)
{
    printf("%s\n", str);
    exit(1);
}

// 스택의 연산들
int is_empty(void) { return top == NULL; }
int is_full(void) { return 0; }
void init_stack(void) { top = NULL; }

// 삽입 연산
void push(Element e)
{
    Node* p = alloc_node(e);
    p->link = top;
    top = p;
}

// 삭제 연산
Element pop(void)
{
    if (is_empty()) {
        error("Underflow Error");
    }
    Node* p = top;
    top = p->link;
    return free_node(p);
}

Element peek()
{
    if (is_empty()) {
        error("Overflow Error");
    }
    return top->data;
}

void destroy_stack(void)
{
    while (is_empty() == 0) {
        pop();
    }
}

int size(void)
{
    int cnt = 0;
    for (Node* p = top; p != NULL; p = p->link) {
        cnt++;
    }
    return cnt;
}

// Node* p = top; -> top 노드의 주소를 p 변수에 복사함