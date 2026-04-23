#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    Element data;
    struct Node* link;
} Node;
Node* rear = NULL;


Node* alloc_node(Element e)
{
    Node* p = (Node*)malloc(sizeof(Node)); // 새로 할당
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

int is_empty(void) { return rear == NULL; }
int is_full(void) { return 0; }
void init_queue(void) { rear = NULL; }

// 삽입 연산
void enqueue(Element e)
{
    Node* p = alloc_node(e);
    if (is_empty()) { // 공백 상태의 삽입
        rear = p; // 새로 할당된 노드 가리키기 (업데이트)
        p->link = p; 
    } else {
        p->link = rear->link;
        rear->link = p;
        rear = p;
    }
}

// 삭제 연산
Element dequeue(void)
{
    if (is_empty()) {
        error("Underflow Error");
    } 

    Node* p = rear->link;
    if (rear == p) {
        rear = NULL; // 변수 초기화
    } else {
        rear->link = p->link;
    }
    return free_node(p);
}

// 탐색(peek) 연산
Element peek(void)
{
    if (is_empty()) {
        error("Underflow Error");
    }
    return rear->link->data;
}

void destroy_queue(void)
{
    while (is_empty() == 0) {
        dequeue();
    }
}