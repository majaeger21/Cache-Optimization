#include <stdlib.h>
#include "matmul.h"

Matrix Allocate2ndMatrix(int height, int width, int init);

void matmul( float*, const float*, const float*, unsigned int, unsigned int, unsigned int);

////////////////////////////////////////////////////////////////////////////////
//! C = A * B
//! @param C          result matrix
//! @param A          matrix A
//! @param B          matrix B
//! @param hA         height of matrix A
//! @param wB         width of matrix B
////////////////////////////////////////////////////////////////////////////////

void matmul(float* C, const float* A, const float* B, unsigned int hA,
    unsigned int wA, unsigned int wB)
{
  for (unsigned int i = 0; i < hA; i+=2)
    for (unsigned int j = 0; j < wB; j+=2) {
      double sum0 = 0;
      double sum1 = 0; // i + 1
      double sum2 = 0; // j + 1
      double sum3 = 0; // i + 1 and j + 1
      for (unsigned int k = 0; k < wA; ++k) {
        double a = A[i * wA + k];
        double b = B[k * wB + j];
        sum0 += a * b;

        a = A[(i + 1) * wA + k];
        b = B[k * wB + j];
        sum1 += a * b;

        a = A[i * wA + k];
        b = B[k * wB + j+1];
        sum2 += a * b;

        a = A[(i + 1) * wA + k];
        b = B[k * wB + j+1];
        sum3 += a * b;

      }
      C[i * wB + j] = (float)sum0;
      C[(i+1) * wB + j] = (float)sum1;
      C[i * wB + j+1] = (float)sum2;
      C[(i+1) * wB + j+1] = (float)sum3;
    }
}

// Allocate a matrix of dimensions height*width
Matrix Allocate2ndMatrix(int height, int width)
{
  Matrix M;
  M.width = M.pitch = width;
  M.height = height;
  int size = M.width * M.height;
  M.elements = NULL;

  M.elements = (float*) malloc(size*sizeof(float));

  for(unsigned int i = 0; i < M.height * M.width; i++)
  {
    M.elements[i] = (rand() / (float)RAND_MAX);
  }
  return M;
}
