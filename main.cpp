#include <iostream>
// #include "matrix.h"
#include "mod26.h"
#include "encrypt.h"
#include "decrypt.h"
#include "string.h"

using namespace std;

void strupr(char *s) {
  for (int i = 0; i < strlen(s); i++) {
    if (s[i] >= 'a' && s[i] <= 'z')
      s[i] -= 32;
  }
}

void elim_sp(char *s) {
  for (int i = 0; i < strlen(s); i++) {
    if (s[i] == ' ') {
      strcpy(s + i, s + i + 1);
      i--;
    }
  }
}

unsigned int chartoint(char s) {
  return s - 65 + 1;
}

char inttochar(unsigned int i) {
  return i - 1 + 65;
}

int main() {
  string input;
  char *s;
  cout << "Insert the text: " << endl;
  getline(cin, input);
  s = new char[input.size()];
  strcpy(s, input.c_str());
  strupr(s);
  elim_sp(s);

  char key[2][2];
  cout << "Insert the key: " << endl;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      cin >> key[i][j];

  unsigned int *m = new unsigned int[strlen(s)];
  for (int i = 0; i < strlen(s); s++)
    m[i] = chartoint(s[i]);

  unsigned int k[2][2];
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      k[i][j] = chartoint(key[i][j]);

  unsigned int *r = new unsigned int[strlen(s)];
  char *rr = new char[strlen(s)];

  encrypt(strlen(s), m, k, r);
  for (int i = 0; i < strlen(s); i++)
    rr[i] = inttochar(r[i]);
  cout << rr;
  return 0;
}
