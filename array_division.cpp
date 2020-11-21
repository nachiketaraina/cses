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
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds ;

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


typedef tree<int, null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

	
int main(){
	
	int n,k ; 
	cin>> n >>k ;
	Vi arr(n ,0);
	for(int i = 0; i < n ; i++){
		cin>>arr[i];
	}
	ordered_set s;
	
	for(int i = 0 ; i <  k ;i++)s.insert(arr[i]);
	
	if(k&1){
		int ans = *s.find_by_order(k/2);
		cout<<ans<<" ";
		for(int i = 0 ; i< n-k ;i++){
			s.erase(s.find_by_order(s.order_of_key(arr[i])));
			s.insert(arr[i+k]);
			ans = *s.find_by_order(k/2);
			cout<<ans<<" ";
		}
		cout<<endl;
	}
	else{
			float ans = ((float)*s.find_by_order(((k+1)/2) - 1)+(float)*s.find_by_order(k/2))/2;
			cout<<ans<<" ";
			for(int i = 0 ; i <n-k ;i++){
				s.erase(s.find_by_order(s.order_of_key(arr[i])));
				s.insert(arr[i+k]);
				ans = ((float)*s.find_by_order(((k+1)/2)-1) + (float)*s.find_by_order(k/2))/2;
				cout<<ans<<" ";
			}
			cout<<endl;
		}
		return 0;
	}
			
	

