#include <vector>
#include <iostream>
#include <stdlib.h>
#include <ctime>

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

bool menor (vector<int> v, int ind1, int ind2) {
  return (v[ind1]<v[ind2]);
}

// v Ã© um vetor com
// n elementos (0 atÃ© n-1)
void selectionsort (vector<int> & v) {
  int n= v.size();
  for (int j=0; j<n-1; j++) {
    int indmin=j;
    for (int k=j+1; k<n; k++) {
      if (menor (v, k, indmin)) {
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

  time_t timeBegin = time(0);
  selectionsort (v);
  time_t timeEnd = time(0);
  double seconds = difftime(timeEnd, timeBegin);
  cout << std::to_string(seconds) + "s";


  //  cout << endl << "=== ORDENADO" << endl;
  //  for (int k=0; k<n; k++) cout << v[k]  << endl;
}