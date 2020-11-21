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

bool check(int64 mid , Vi &dead , int n ,int k){
	int count =0 ;
	int64 sum = 0;
	for(int i = 0 ; i < n ; i++){
		if(dead[i]>mid)return false;
		
		sum+=dead[i];
		
		if(sum>mid){
			count+=1;
			sum = dead[i];
		}
	}
	count++;
	if(count<=k)return true;
	return false;
	
}
	
int main(){
	
	int n,k ; 
	cin>> n >>k ;
	Vi dead(n ,0);
	for(int i = 0; i < n ; i++){
		cin>>dead[i];
	}
/*	sort(dead.begin() ,dead.end() ,[](vector<int> a,vector<int> b){
		if((a[1]- a[0]) == (b[1] - b[0]))return a[1]<b[1]?true:false;
		else a[1]-a[0]>b[1]-b[0]?true:false; });
	*/
	int64 end = accumulate(dead.begin(),dead.end(),0),start = 0 , ans =0;
	while(end>=start){
		int64 mid = (end+start)/2;
		if(check(mid,dead,n,k)){
			ans = mid;
			end= mid-1;
		}
		else{
			start = mid+1;
		}
	}
	cout<<ans;
	return 0;
}
