/*
코드 2.6 희소 행렬의 표현
*/
#include <stdio.h>

// 정방행렬 전치 연산의 경우, 행과 열만 바꿔주면 됨

typedef struct {
    int row;
    int col;
    int value;
} Elem;

void transpose_mat2(Elem mat[], int len)
{
    for (int i = 0; i < len; i++) {
        int tmp = mat[i].col;
        mat[i].col = mat[i].row;
        mat[i].row = tmp;
        // 구조체 추상화로 인해 전치행렬 시 값은 안 바꿔도 됨
    }
}

void print_mat2(Elem mat[], int len, const char* str)
{
    printf("%s", str);
    for (int i = 0; i < len; i++) {
        printf(" (%d,%d,%d)", mat[i].row, mat[i].col, mat[i].value);
    }
    printf("\n");
}

int main(void) 
{
    Elem mat[5] = {
        {0, 2, 2}, {2, 3, 7}, {3, 0, 1},
        {4, 5, 3}, {5, 1, 5}
    }; // value != 0인 요소 [Row][Col][Value]
    print_mat2(mat, 5, "희소행렬");
    transpose_mat2(mat, 5);
    print_mat2(mat, 5, "전치행렬");

    return 0;    
}