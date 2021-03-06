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
typedef struct
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

// Column Vec 3 float, for the rotation matrices
typedef struct
{
    float m[3];
}cv3f;



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


cv3f cv3f_new(float m1[3])
{
    cv3f c;
    for(int i = 0; i < 3; i++)
    {
        c.m[i] = m1[i];
    }
    return c;
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
    //Cross product of x,y vectors is a vector in z direction
    //returns z vector float

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

m2s m2s_inverse(m2s mat, float determinant)
{
    // Takes the inverse of matrix mat by multiplying each element by 
    // inverse of the determinant
    // returns mat of same dimension
    m2s inverse;
    float inv_factor, temp;
    
    inv_factor = 1.0 / determinant;
    
    // Switch the 0,0 and the 1,1
    temp = mat.m[0][0];
    mat.m[0][0] = mat.m[1][1];
    mat.m[1][1] = temp;
    
    // Negate the 0,1 and 1,0
    mat.m[0][1] = -1.0 * mat.m[0][1];
    mat.m[1][0] = -1.0 * mat.m[1][0];

    // Multiply each by 1 / determinant
    for(int i = 0;i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            inverse.m[i][j] = mat.m[i][j] * inv_factor;
        }
    }

    return inverse;
}


m3s m3s_zerofill()
{
    m3s z;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            z.m[i][j] = 0.0;
        }
    }
    return z;
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

// for rotations I need 4 functions
// rm_pitch, rm_roll, rm_yaw
// multiply a column mat X,Y,Z by a 3x3 rotation matrix

// http://planning.cs.uiuc.edu/node102.html

m3s m3s_pitchrot(float sigma)
{
    m3s rm;
    rm = m3s_zerofill();

     
    rm.m[0][0] = cos(sigma);
    rm.m[0][2] = sin(sigma);
    rm.m[1][1] = 1.0; 
    rm.m[2][0] = -1.0 * sin(sigma);
    rm.m[2][2] = cos(sigma);
        
    return rm;
}

m3s m3s_rollrot(float sigma)
{
    m3s rm;
    rm = m3s_zerofill();
    
    rm.m[0][0] = 1.0;
    rm.m[1][1] = cos(sigma);
    rm.m[1][2] = -1.0 * sin(sigma); 
    rm.m[2][1] = sin(sigma);
    rm.m[2][2] = cos(sigma);
    
    return rm;


}


m3s m3s_yawrot(float sigma)
{
    m3s rm;
    rm = m3s_zerofill();
     
    rm.m[0][0] = cos(sigma);
    rm.m[0][1] = -1.0 * sin(sigma);
    rm.m[1][0] = sin(sigma);
    rm.m[1][1] = cos(sigma);
    rm.m[2][2] = 1.0;
    return rm;
}


cv3f cv3f_m3s_multiply(cv3f xyz, m3s rotmat)
{
    cv3f xyz_prime;
    int temp =0;
    for(int i = 0; i < 3; i++)
    {
        xyz_prime.m[i] = 0.0;
        for(int j = 0; j < 3; j++)
        {
            xyz_prime.m[i] += (rotmat.m[i][j] * xyz.m[j]);
           
        }
    }
    return xyz_prime;
}


cv3f rpy_translation(cv3f xyz, float alpha, float beta, float gamma)
{
    // alpha: roll, beta: pitch, gamma: yaw
    m3s rm_roll = m3s_rollrot(alpha);
    m3s rm_pitch = m3s_pitchrot(beta);
    m3s rm_yaw = m3s_yawrot(gamma);

    cv3f resulting;
    // for each rotation:
    // resulting x',y',z' = multiply(xyz, rm_roll)
    
    resulting = cv3f_m3s_multiply(xyz, rm_roll);
    resulting = cv3f_m3s_multiply(resulting, rm_pitch);
    resulting = cv3f_m3s_multiply(resulting, rm_yaw);
    return resulting;
}







