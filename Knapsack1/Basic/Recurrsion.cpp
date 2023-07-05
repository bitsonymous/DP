#include <iostream>
using namespace std;
int knapsack(int w[], int v[], int c, int n){
	if(n == 0 || c == 0) return 0;
	else{
		if(w[n-1]<=c){
			return max(v[n-1]+knapsack(w,v,c-w[n-1],n-1),knapsack(w,v,c,n-1));
		}else{
			return knapsack(w,v,c,n-1);
		}
	}
}
int main() {
	int n,c;
	cin>>n>>c;
	int v[n], w[n];
	for(int i =0; i<n; i++){
		cin>>v[i];
	}
	for(int i =0; i<n; i++){
		cin>>w[i];
	}
	int ans = knapsack(w,v,c,n);
	cout<<ans<<endl;
}