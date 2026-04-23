/*
코드 3.6 후위 표기식 계산 프로그램
*/
#define MAX_SIZE 100
typedef double Element;
#include "ArrayStack.h"

float eval_postfix(const char expr[])
{
  int i = 0;
  init_stack();
  while (expr[i] != '\0')
  {
    char ch = expr[i++];
    if (ch >= '0' && ch <= '9')
    {
      double num = (double)ch - '0'; // 아스키 코드값
      push(num);
    }
    else if (ch == '+' || ch == '-' ||
             ch == '*' || ch == '/')
    {
      float val2 = pop();
      float val1 = pop();
      switch (ch)
      {
      case '+':
        push(val1 + val2);
        break;

      case '-':
        push(val1 - val2);
        break;

      case '*':
        push(val1 * val2);
        break;

      case '/':
        push(val1 / val2);
      break;
      }
    }
  }
  return pop(); // 계산 후 결과값 return 
}

int main(void)
{
  char expr[2][80] = {
      "8 2 / 3 - 3 2 * +",
      "1 2 / 4 * 1 4 / *"
  };

  printf("수식: %s = %lf\n", expr[0], eval_postfix(expr[0]));
  printf("수식: %s = %lf\n", expr[1], eval_postfix(expr[1]));

  return 0;
}