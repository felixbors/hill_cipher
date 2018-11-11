#ifndef HILL_CIPHER_MATRIX_H
#define HILL_CIPHER_MATRIX_H
#include <iostream>
using namespace std;

class Matrix {
 protected:
  unsigned int m, n, **mat;
 public:

  Matrix() {
    m = n = 0;
    mat = NULL;
  }

  Matrix(unsigned int m) {
    this->m = m;
    this->n = m;
    mat = new unsigned int *[m];
    for (int i = 0; i < m; i++) {
      mat[i] = new unsigned int[n];
    }
    if (!mat) {
      cout << "Eroare la alocare" << endl;
    }
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) {
        mat[i][j] = 0;
      }
  }

  Matrix(unsigned int m, unsigned int n) {
    this->m = m;
    this->n = n;
    mat = new unsigned int *[m];
    for (int i = 0; i < m; i++) {
      mat[i] = new unsigned int[n];
    }
    if (!mat) {
      cout << "Eroare la alocare" << endl;
    }
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) {
        mat[i][j] = 0;
      }
  }

  Matrix(unsigned int m, unsigned int n, unsigned int **Mat) {
    this->m = m;
    this->n = n;
    this->mat = new unsigned int *[m];
    for (int i = 0; i < m; i++) {
      this->mat[i] = new unsigned int[n];
    }
    if (!mat) {
      cout << "Eroare la alocare" << endl;
    }
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) {
        this->mat[i][j] = Mat[i][j];
      }
  }

  ~Matrix() {
    for (int i = 0; i < m; i++)
      delete[] mat[i];
  }

  void afisare() const;

  friend bool inner_dim(Matrix M, Matrix N);

};

void Matrix::afisare() const {
  if (m && n && mat) {
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cout << mat[i][j] << " ";
      }
      cout << endl;
    }
  } else {
    cout << "Eroare" << endl;
  }
}

bool inner_dim(Matrix M, Matrix N) {
  if (M.mat != NULL && N.mat != NULL) {
    if (M.n == N.m) {
      return true;
    }
  }
  return false;
}

class Square_Matrix_2_2 : public Matrix {
 public:
  Square_Matrix_2_2() : Matrix(2) {
  }
  Square_Matrix_2_2 operator=(const unsigned int M[2][2]) {
    this->mat[0][0] = M[0][0];
    this->mat[0][1] = M[0][1];
    this->mat[1][0] = M[1][0];
    this->mat[1][1] = M[1][1];
    return *this;
  }

};

#endif //HILL_CIPHER_MATRIX_H
