#include <bits/stdc++.h>
using namespace std;

int knapsack(int w[], int v[], int c, int n,vector<vector<int>> &t){
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=c; j++){
			if(w[i-1]<=j){
				t[i][j] = max(v[i-1]+t[i-1][j-w[i-1]],t[i-1][j]);
			}else{
				t[i][j] = t[i-1][j];
			}
		}
	}
	return t[n][c];
}
int main() {
	int n,c;
	cin>>n>>c;
	int v[n], w[n];
	vector<vector<int>> t(n+1, vector<int> (c+1, 0));
	for(int i =0; i<n; i++){
		cin>>v[i];
	}
	for(int i =0; i<n; i++){
		cin>>w[i];
	}
	int ans = knapsack(w,v,c,n,t);
	cout<<ans<<endl;
}