//===-- ola.h - Owen's Linear Algebra Header Library -------*- C -*-===//
//
// This is the  base file for the ola library
// Header only library
// 11/21/21
//===----------------------------------------------------------------------===//


#include <math.h>

// Vector 2 float: v2f
typedef struct
{
    float c[2];
}v2f;

// Vector 3 float: v3f
typedef struct;
{
    float c[3];
}v3f;


// Matrix 2 square: m2s
typedef struct
{
    float m[2][2];
}m2s;

//Matrix 3 square: m3s
typedef struct
{
    float m[3][3];
}m3s;




v2f v2f_new(float x, float y)
{
    v2f v;
    v.c[0] = x;
    v.c[1] = y;
    return v;
}

m2s m2s_new(float m1[2][2])
{
    m2s mat;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            mat.m[i][j] = m1[i][j];
        }
    }
    return mat;
}

m3s m3s_new(float m1[3][3])
{
    m3s mat;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            mat.m[i][j] = m1[i][j];
        }
    }
    return mat;
}


// -----Functions-----

float v2f_dotProduct(v2f vec1, v2f vec2)
{
    float sum, product;
    
    for(int i = 0; i < 2; i++)
    {
        product = vec1.c[i] * vec2.c[i];
        sum += product;
    }

    return sum;
}


float v2f_crossProduct(v2f vec1, v2f vec2)
{
    // A x B = <(AyBz - AzBy),(AzBx - AxBz),(AxBy - AyBx)>
    //Cross product of x,y vectors is a scalar in the z direction
    //returns scalar float

    float cz;
    
    cz = vec1.c[0] * vec2.c[1] - vec1.c[1] * vec2.c[0];

    return cz;
}


// ----Matrix----

float m2s_determinant(m2s mat)
{
    // det(mat) = (a * d) - (b * c)
    // mat =  |a c|
    //        |b d|
    // returns scalar float

    float crossAD, crossBC;

    crossAD = mat.m[0][0] * mat.m[1][1];
    crossBC = mat.m[0][1] * mat.m[1][0];

    return crossAD - crossBC;
}

m2s m2s_transpose(m2s mat)
{
    // Transpose of mat denoted mat^t of a square 2x2 matrix
    //  |a c|  =  |a b|
    //  |b d|     |c d|
    // returns m2s
    m2s mat_t;

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            mat_t.m[i][j] = mat.m[j][i];
        }
    }
    return mat_t;
}


m3s m3s_transpose(m3s mat)
{
    // Transpose of mat denoted mat^t of a square 3x3 matrix
    // returns m3s
    m3s mat_t;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            mat_t.m[i][j] = mat.m[j][i];
        }
    }
    return mat_t;
}





