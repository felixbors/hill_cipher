#ifndef HILL_CIPHER_ENCRYPT_H
#define HILL_CIPHER_ENCRYPT_H

void inmultire(unsigned int m[2], unsigned int k[2][2], unsigned int rez[2]) {
  rez[0] = m[0] * k[0][0] + m[1] * k[1][0];
  rez[1] = m[0] * k[0][1] + m[1] * k[1][1];
}

void encrypt(unsigned int n, unsigned int m[], unsigned int key[2][2], unsigned int rez[]) {
  unsigned int _m[2], _r[2];
  for (int i = 0; i < n - 1; i += 2) {
    _m[0] = m[i];
    _r[0] = rez[i];
    _m[1] = m[i + 1];
    _r[1] = rez[i + 1];
    inmultire(_m, key, _r);
    rez[i] = _r[0];
    rez[i + 1] = _r[1];
  }
}

#endif //HILL_CIPHER_ENCRYPT_H
