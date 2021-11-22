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
    m2s mat1;
    float m1[2][2] = {{1.0, 2.0},{3.0, 4.0}};

    mat1 = m2s_new(m1);
    
    //Operations

    m2s mat2;

    mat2 = m2s_transpose(mat1);
    
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            printf("Matrix elements %d , %d : %f\n", i, j, mat2.m[i][j]);
        }
    }

    return 0;
}


