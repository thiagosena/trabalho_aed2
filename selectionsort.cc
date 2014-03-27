#include <vector>
#include <iostream>
#include <stdlib.h>

// Por que este programa demora tanto quando o nÃºmero de elementos Ã© 25000?
// Por que dÃ¡ problema de memÃ³ria quando o nÃºmero de elementos Ã© 100000?
// (Os valores acima variam de computador para computador obviamente.)
// Mostre que suas hipÃ³teses sÃ£o verdadeiras.

using namespace std;

void SWAP (int &x, int &y) {
  int aux = x;
  x=y;
  y=aux;
}

// v Ã© um vetor com
// n elementos (0 atÃ© n-1)
void selectionsort (vector<int> & v) {
  int n= v.size();
  for (int j=0; j<n-1; j++) {
    int indmin=j;
    for (int k=j+1; k<n; k++) {
      if (v[k]<v[indmin]) {
  indmin=k;
      }
    }
    SWAP (v[j], v[indmin]);
  }
}

int main () {
  vector<int> v;
  cout << "Numero de elementos: ";
  int n;
  cin >> n;
  srand (1); // Sempre a mesma sequÃªncia
  for (int k=0; k<n; k++)
    v.push_back (rand());

  //  cout << "=== NÃƒO ORDENADO" << endl;
  //  for (int k=0; k<n; k++) cout << v[k]  << endl;

  selectionsort (v);

  //  cout << endl << "=== ORDENADO" << endl;
  //  for (int k=0; k<n; k++) cout << v[k]  << endl;
}