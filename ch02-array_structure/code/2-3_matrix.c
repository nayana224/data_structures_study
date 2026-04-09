/*
의문점: 정방행렬이 아닌 경우에는 어떻게 하는가?

*/
#include <stdio.h>

#define ROWS 3
#define COLS 3

void print_mat(int mat[ROWS][COLS], const char *label)
{
    printf("%s:\n", label);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%3d ", mat[i][j]);
        }
        printf("\n");
    }
}

void transpose_mat(int mat[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = i+1; j < COLS; j++) {
            int tmp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = tmp;
        }
    }
}


int main(void)
{
    int mat[ROWS][COLS] = { 4, 0, 1,  1, 6, 5,  7, 3, 6};
    print_mat(mat, "원래 행렬");
    transpose_mat(mat);
    print_mat(mat, "전치 행렬");

    return 0;
}