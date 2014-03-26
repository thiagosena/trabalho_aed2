#include <iostream>
#include <stdio.h>   
#include <math.h>
#include <stdlib.h>
#include <limits.h>

using namespace std;


int partition ( int a[], int n ){
	int sum = 0;
	for(int i = 0; i < n; i++)
    	sum += a[i];

	int *s = new int[sum+1];

	s[0] = 1;
	for(int i = 1; i < sum+1; i++)    
		s[i] = 0;

	int diff = INT_MAX , ans;

	for(int i = 0; i < n; i++){
    	for(int j = sum; j >= a[i]; j--){
        	s[j] = s[j] | s[j-a[i]];
        	if(s[j] == 1){
            	if(diff > abs(sum/2 - j)){
                	diff = abs(sum/2 - j);
                	ans = j;
            	}
        	}
    	}
	}
	return sum-ans-ans;
}

int main(){
    int n,result, arr[300];
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    result = partition(arr,n);

	/* Se a diferenca entre a soma dos subconjuntos for igual a 0 
	 * entao o conjunto pode ser dividido.
	 */
	if(abs(result) == 0) 
		cout << "O conjunto informado pode ser dividido em dois subconjuntos com somas iguais." << endl;
	else
		cout << "O conjunto informado NAO PODE ser dividido em dois subconjuntos com somas iguais." << endl;

    return 0;
}