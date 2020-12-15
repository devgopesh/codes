#include<iostream>
using namespace std;

int main(){
	int best = 0,sum = 0,n;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	for (int k = 0; k < n; k++) { 
		sum = max(array[k],sum+array[k]); 
		best = max(best,sum); 
	} 
	cout << best << "\n";
	return 0;
}
