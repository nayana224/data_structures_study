typedef int Element;
#include "LinkedStack.h"

void print_recur(Node* p)
{
    if (p != NULL) {
        print_recur(p->link);
        printf("%3d", p->data);
    }
}

void print_stack(Node* p)
{
    for (; p != NULL; p = p->link) {
        printf("%3d", p->data);
    }
}

int main(void)
{
    int A[7] = {0, 1, 1, 2, 3, 5, 8};

    init_stack();
    printf("[스택 테스트]\n입력 데이터: ");
    for (int i=0; i<7; i++) {
        printf("%3d", A[i]);
        push(A[i]);
    }
    printf("\n스택 사이즈: %d", size());
    printf("\n입력된 순서대로 출력: ");
    print_recur(top);
    printf("\n입력의 역순으로 출력: ");
    print_stack(top);

    printf("\n출력 데이터: ");
    while (!is_empty()) {
        printf("%3d", pop());
    }
    printf("\n");
    
    destroy_stack();
    return 0;
}