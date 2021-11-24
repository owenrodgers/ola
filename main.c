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

    // Matrix
    m2s mat1, mat1_inverse, mat1_identity;
    float determinant;
    float m1[2][2] = {{4, 7},{2, 6}};
    
    mat1 = m2s_new(m1);
    determinant = m2s_determinant(mat1);

    mat1_inverse = m2s_inverse(mat1, determinant);
    
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            printf("%f\n", mat1_inverse.m[i][j]);
        }
    }

    return 0;
}


