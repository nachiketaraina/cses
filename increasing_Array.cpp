#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
using namespace std;

#define MP make_pair
#define PB push_back
#define ARR_MAX (int)1e5 //Max array length
#define INF (int)1e9 //10^9
#define EPS 1e-9 //10^-9
#define MOD 1000000007 //10^9+7
#define PI 3.1415926535897932384626433832795
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
typedef pair<int, int> Pii;
typedef vector<int> Vi;
typedef vector<string> Vs;
typedef vector<Pii> VPii;
typedef vector<Vi> VVi;
typedef map<int,int> Mii;
typedef set<int> Si;
typedef multimap<int,int> MMii;
typedef multiset<int> MSi;
typedef unordered_map<int,int> UMii;
typedef unordered_set<int> USi;
typedef unordered_multimap<int,int> UMMii;
typedef unordered_multiset<int> UMSi;
typedef priority_queue<int> PQi;  //maxheap
typedef priority_queue<int,Vi,greater<int>> min_h ; //minheap
typedef queue<int> Qi;
typedef deque<int> DQi;
int minpar(vector<int> &v,int i,int32 temps,int s){
	if(i==0)return abs((s-temps)-temps);
	
	return min(minpar(v,i-1,temps+v[i-1],s),minpar(v,i-1,temps,s));
}
int main(){
	int n;
	cin>>n;
	vector<int> v;
	for(int i = 0 ; i < n ;i++){
		int t;
		cin>>t;
		v.push_back(t);
	}
	int s = accumulate(v.begin(),v.end(),0);
	cout<< minpar(v,v.size(),0,s);
	
	return 0;
	
}
