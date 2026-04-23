/*
코드 3.10 하노이의 탑
*/
#include <stdio.h>

void hanoi_tower(int n, char from, char tmp, char to)
{
  if (n==1) {
    printf("원판 1: %c --> %c\n", from, to);
  } else {
    hanoi_tower(n-1, from, to, tmp); // 임시 기둥으로 옮기기
    printf("원판 %d: %c --> %c\n", n, from, to); // 목표 기둥으로 옮기기
    hanoi_tower(n-1, tmp, from, to); // 임시기둥
  }
}

int main(void)
{
  int n;

  printf("원판 개수 입력: ");
  if (scanf("%d", &n) != 1 || n < 1) {
    printf("1 이상의 정수를 입력하세요.\n");
    return 1;
  }

  printf("\n하노이 타워 이동 순서\n");
  hanoi_tower(n, 'A', 'B', 'C');

  return 0;
}
