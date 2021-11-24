#include <stdio.h>
#include <stdlib.h>


#define LA_IMPLEMENTATION
#include "ola.h"

//cc -o la_usage la_usage.c

void show(m2s mat);


int main()
{
    // find inverse of a matrix

    float mat1_determinant;
    float mat1_data[2][2] = {{4.0, 7.0},{2.0, 6.0}};
    
    m2s mat1, mat1_inverse;

    mat1 = m2s_new(mat1_data);
    mat1_determinant = m2s_determinant(mat1);

    mat1_inverse = m2s_inverse(mat1, mat1_determinant);
   
    printf("Matrix 1\n");
    show(mat1);

    printf("Inverse of Matrix 1\n");
    show(mat1_inverse);
    return 0;
}


void show(m2s mat)
{
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            printf(" %f ", mat.m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}



