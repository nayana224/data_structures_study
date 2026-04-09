/*
코드 2.5 구조체를 매개변수로 전달
*/
#include <stdio.h>

typedef struct {
    double real;
    double imag;
} Complex;

void reset_complex(Complex *a)
{
    a->real = 0.0;
    a->imag = 0.0;
}

void print_complex(Complex *a) 
{
    printf("%4.1f + %4.1fi\n", a->real, a->imag);
}

int main(void)
{
    Complex a;
    a.real = 1.0;
    a.imag = 2.0;
    printf("초기화 이전: ");
    print_complex(&a);

    reset_complex(&a);
    printf("초기화 이후: ");
    print_complex(&a);

    return 0;
}