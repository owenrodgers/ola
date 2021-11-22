#include <stdio.h>
#include <stdlib.h>

#define OLA_IMPLEMENTATION
#include "ola.h"

// clang -o main main.c
// ./main

// example usage for ola.h library

int main()
{
    printf("ola implementation \n");

    //Vector 
    v2f vec1;
   
    vec1 = v2f_new(4.0, 3.0);

    //Matrix
    m2s mat1, mat1_inverse;
    float m1_det;
    float m1[2][2] = {{11.0, 9.0},{17.0, 2.0}};

    mat1 = m2s_new(m1);
    m1_det = m2s_determinant(mat1);
    mat1_inverse = m2s_inverse(mat1, m1_det);

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            printf("%d , %d : %f\n", i, j, mat1_inverse.m[i][j]);
        }
    }

    return 0;
}


