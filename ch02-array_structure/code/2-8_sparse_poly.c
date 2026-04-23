/*
코드 2.8 희소 다항식 프로그램
*/

#include <stdio.h>
#include <math.h>
#define MAX_TERMS 80

// 하나의 항을 위한 구조체
typedef struct {
    int expo; // 지수
    float coef; // 계수
} Term;

// 희소 다항식 구조체
typedef struct {
    int nTerms; // 항의 개수
    Term term[MAX_TERMS]; // 항의 배열
} SparsePoly;


SparsePoly add(SparsePoly a, SparsePoly b) // [복습] -> 어려움
{
    SparsePoly c;
    c.nTerms = 0;
    
    // 초기화와 조건식 기반 반복문
    // - 루프 종료 조건: 두 다항식 중 어느 하나라도 남으면 루프 계속 돌림
    // - i, j: 다항식 A와 B의 몇 번째 항을 보고있는지 나타냄
    for (int i = 0, j = 0; i < a.nTerms || j < b.nTerms;) {
        // 다항식 A의 항이 끝나거나, b의 지수가 더 클 경우
        if (i == a.nTerms || a.term[i].expo < b.term[j].expo) {
            c.term[c.nTerms++] = b.term[j++]; // b의 항 추가
        } 
        // 다항식 B의 항이 끝나거나, a의 지수가 더 클 경우
        else if (j == b.nTerms || a.term[i].expo > b.term[j].expo) {
            c.term[c.nTerms++] = a.term[i++]; // a의 항 추가
        } 
        // 다항식 A의 항과 B의 지수가 동일한 경우
        else {
            c.term[c.nTerms] = a.term[i++]; // a항을 대입 후
            c.term[c.nTerms++].coef += b.term[j++].coef; // a, b의 계수를 더함
        }
    }

    return c;
}


float evalute(SparsePoly a, float x) // [복습] -> 어려움
{
    float result = 0;
    for (int i = 0; i < a.nTerms; i++) {
        result += (float)(a.term[i].coef * pow(x, a.term[i].expo));
    }
    return result;
}


void print_spoly(SparsePoly p, const char* str)
{
    printf("%s", str);

    for (int i = 0; i < p.nTerms; i++) {
        printf("%5.1f", p.term[i].coef);
        if (p.term[i].expo > 0) {
            printf(" x^%d ", p.term[i].expo);
            if (i != p.nTerms - 1) printf("+ ");
        }
    }
    printf("\n");
}

int main(void)
{
    SparsePoly a = {2, {{100, 10.0f}, {0, 6.0f}}};
    SparsePoly b = {2, {{50, 1.1f}, {3, 2.0f}}};
    SparsePoly c = add(a, b);

    print_spoly(a, " A = ");
    print_spoly(b, " B = ");
    print_spoly(c, " A+B = ");
    printf("A(1)= %f\n", evalute(a, 1.0f));
    printf("B(2)= %f\n", evalute(b, 2.0f));

    return 0;
}

