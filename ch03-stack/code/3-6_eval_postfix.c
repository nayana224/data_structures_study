#define MAX_SIZE 100
typedef double Element;
#include "ArrayStack.h"

float eval_postfix(const char expr[]) 
{
   
}


int main(void)
{
  char expr[2][80] = {
    "8 2 / 3 - 3 2 * +",
    "1 2 / 4 / * 1 4 / *"
  };

  printf("수식: %s = %lf\n", expr[0], eval_postfix(expr[0]));
  printf("수식: %s = %lf\n", expr[1], eval_postfix(expr[1]));

  return 0;
}