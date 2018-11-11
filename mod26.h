#ifndef HILL_CIPHER_MOD26_H
#define HILL_CIPHER_MOD26_H
#include <iostream>
using namespace std;


 unsigned int det(unsigned int M[2][2]) {
  return (26+M[0][0]*M[1][1]-M[0][1]*M[1][0])%26;
}

unsigned int inv(unsigned int a) {
  if(a%2==0)
    return 0;
  for (int i=1;i<=25;i++)
    if(a*i%26==1)
      return i;
  return 0;
}

void inv22mod26(unsigned int M[2][2], int Minv[2][2]) {
  if(inv(det(M))) {
    Minv[0][0]=M[1][1];
    Minv[0][1]=-M[0][1];
    Minv[1][0]=-M[1][0];
    Minv[1][1]=M[0][0];
    for(int i=0;i<2;i++)
      for(int j=0;j<2;j++) {
        Minv[i][j]*=inv(det(M));
        Minv[i][j]%=26;
        Minv[i][j]+=26;
        Minv[i][j]%=26;
      }
  }
  else {
    cout<<"Eroare, matrice neinversabila"<<endl;
  }


}

#endif //HILL_CIPHER_MOD26_H
