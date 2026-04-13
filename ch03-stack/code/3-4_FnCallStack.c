/*
코드 3.4 스택에 구조체 저장하기
*/
#define MAX_SIZE 100
typedef struct
{
  char name[32];
  int param;
} Element;
#include "ArrayStack.h"

int main(void)
{
  Element calls[4] = {
      {"main()"},
      {"factorial()", 3},
      {"factorial()", 2},
      {"factorial()", 1}};

  init_stack();
  printf("함수 호출 순서: \n");
  for (int i = 0; i < 4; i++) {
    push(calls[i]);
    printf("\t%s %d\n", calls[i].name, calls[i].param);
  }

  printf("함수 반환 순서: \n");
  for (int i=0; i<4; i++) {
    Element call = pop();
    printf("\t%s %d\n", call.name, call.param);
  }

  return 0;
}