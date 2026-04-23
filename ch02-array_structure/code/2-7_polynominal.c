/*
코드 2.7 다항식 프로그램
*/
#include <stdio.h>
#define MAX_DEGREE 1001

typedef struct {
    int degree;
    float coef[MAX_DEGREE];
} Polynominal;



void print_poly(Polynominal p, const char* str)
{
    printf("%s", str);
    for (int i = p.degree; i > 0; i--) {
        printf("%5.1f x^%d + ", p.coef[i], i);
    }
    printf("%4.1f\n", p.coef[0]);
}

// 다항식 값 대입 연산
float evalute(Polynominal p, float x)
{
    float result = p.coef[0]; // 상수항으로 초기화
    float mul = 1;
    for (int i = 1; i <= p.degree; i++) {
        mul *= x;
        result += p.coef[i] * mul;
    }

    return result;
}

// 다항식끼리의 덧셈
Polynominal add(Polynominal a, Polynominal b) // [복습] -> 어려움
{
    Polynominal p; // 다항식 결과
    p.degree = (a.degree > b.degree) ? a.degree : b.degree; // 최고차수 결정

    for (int i = 0; i < p.degree; i++) { // i : 차수
        p.coef[i] = ((i <= a.degree) ? a.coef[i] : 0) + ((i <= b.degree) ? b.coef[i] : 0);
    }

    return p;
}


int main(void)
{
    Polynominal a = {5, {3, 6, 0, 0, 0, 10}};
    Polynominal b = {4, {7, 0, 5, 0, 1}};
    Polynominal c = add(a, b);

    print_poly(a, " A = ");
    print_poly(b, " B = ");
    print_poly(c, " A+B = ");

    printf("A(1) = %f\n", evalute(a, 1.0f));
}