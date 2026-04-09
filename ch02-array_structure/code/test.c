#include <stdio.h>
#include <string.h>

typedef struct Student_t {
    int id;
    char name[20];
    double score;
} Student;

int main(void)
{
  Student a = {2024111, "홍길동", 80.8};
  printf("학번: %d\n", a.id);
  printf("이름: %s\n", a.name);
  printf("성적: %.2f\n", a.score);   
  
  a.id = 2000;
  strncpy(a.name, "홍수아", 20);
  a.score = 100.0;

  printf("학번: %d\n", a.id);
  printf("이름: %s\n", a.name);
  printf("성적: %.2f\n", a.score); 

  return 0;
}