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
#include <climits>
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
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
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

// Driver Code 
int main() 
{ 	
	
	fast_io;
    int n;
    cin>>n;
    Vi arr(n);
    for(auto &v:arr)cin>>v;
	vector<vector<bool>>dp(n+1,vector<bool>(n*1000+1,false));
	dp[0][0]=true;
	for(int i = 1 ; i <= n ;i++){
		for(int j = 0 ; j<= n*1000 ;j++){
			dp[i][j]=dp[i-1][j];
			int l  = j-arr[i-1];
			if(l>=0 and dp[i-1][l] ==  true)dp[i][j]=true;
		}
	}
	Vi res;
	for(int j=1 ; j <= n*1000 ;j++)if(dp[n][j])res.push_back(j);
	
	cout<<res.size()<<endl;
	for(int v:res)cout<<v<<" ";

    return 0; 
}
