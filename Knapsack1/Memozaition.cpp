#include <bits/stdc++.h>
using namespace std;

int knapsack(int w[], int v[], int c, int n,vector<vector<int>> &t){
	if(n == 0 || c == 0) return 0;
	if(t[c][n]!=-1){
		return t[c][n];
	}
	else{
		if(w[n-1]<=c){
			return t[c][n] = max(v[n-1]+knapsack(w,v,c-w[n-1],n-1,t),knapsack(w,v,c,n-1,t));
		}else{
			return t[c][n] = knapsack(w,v,c,n-1,t);
		}
	}
}
int main() {
	int n,c;
	cin>>n>>c;
	int v[n], w[n];
	vector<vector<int>> t(c+1, vector<int> (n+1, -1));
	for(int i =0; i<n; i++){
		cin>>v[i];
	}
	for(int i =0; i<n; i++){
		cin>>w[i];
	}
	int ans = knapsack(w,v,c,n,t);
	cout<<ans<<endl;
}