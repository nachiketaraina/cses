#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,res=0;
	cin >> n;
	vector<vector<int>> s;
	for(int i = 0 ; i < n ;i++){
		int a,b;
		cin>>a>>b;
		s.push_back({a,0});
		s.push_back({b,1});
	}
	
	for(int i = 0 ; i < s.size() ;i++){
		if(s[i][1]==0){
			res++;
			cout<<res<<" ";
		}
		else {
			res--;
			cout<<res<<" ";
		}
	}

	return 0;
}
