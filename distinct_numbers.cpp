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
bool col[16],diag1[16],diag2[16], reserved[8][8];

int main(){
	
	int n,m,k,pappl=0,papart = 0,res=0;
	cin>>n>>m>>k;
	vector<int> applc(n),apartc(m);
	for(int i = 0 ; i< n ;i++){
		int t;
		cin>>t;
		applc.push_back(t);
	}
	for(int i =0 ;i< m ;i++){
		int t;
		cin>>t;
		apartc.push_back(t);
	}
	sort(applc.begin(),applc.end());
	sort(apartc.begin(),apartc.end());
	while(papart < m && pappl < n){
		 if(apartc[papart]<=applc[pappl] +k && apartc[papart] >= applc[pappl]-k){
			 res++;
			 pappl++;
			 papart++;
		 }
		 else if(apartc[papart]<applc[pappl] -k) papart++;
		 else pappl++;
	 }
	 cout<<res;
	return 0;
	
	}
 
