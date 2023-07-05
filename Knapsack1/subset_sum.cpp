#include <bits/stdc++.h>
using namespace std;
void subset(vector<int> &w, vector<vector<int>> &ans, vector<int> &ds, int n , int k, int i = 0){
	if(i == n || k == 0){
		if(k==0){
			sort(ds.begin(), ds.end());
			ans.push_back(ds);
		} 
		return;
	}
	ds.push_back(w[i]);
	subset(w, ans , ds, n , k - w[i], i+1 );
	ds.pop_back();
	while(i+1<n && w[i] == w[i+1] ) i++;
	subset(w, ans , ds, n, k, i+1);
}
int main() {
	int n,k;
	cin>>n>>k;
	vector<int> w(n);
	for(int i = 0; i<n; i++){
		cin>>w[i];
	}
	sort(w.begin(),w.end());
	vector<vector<int>>ans;
	vector<int> ds;
	subset(w,ans, ds, n , k);
	for(int i = 0; i<ans.size(); i++){
		for(int j = 0; j<ans[i].size(); j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
}