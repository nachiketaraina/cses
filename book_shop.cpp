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
    int n , m ;
     cin>>n>>m;
     Vi val(n);
     
	  
	  VVi dp(n , Vi(m,0));
	  
	  int start ;
	   cin>>start;
	   if(start==0){
		   fill(dp[0].begin(),dp[0].end(),1);
	   }
	   else dp[0][start] = 1;
	   
	   for(int i =1 ; i<n ;i++){
		   
			   int beg ;
			   cin>>beg;
			   if(beg==0){
				   for(int j =1 ; j<=m ;j++){
					   for(int k :{j-1,j,j+1}){
						   if(k>=1 && k<=m){
							   dp[i][j]+=dp[i-1][k]%=MOD;
						   }
					   }
				   }
			   }
			   else{
				   for(int k : {beg-1,beg,beg+1}){
					   if(k>=1 &&k<=m){
						   dp[i][beg]+=dp[i-1][k]%=MOD;
					   }
				   }
			   }
		   }
		   int res = 0 ;
		   for(int j = 1 ;j<=m ;j++)res+=dp[n-1][j]%=MOD;
		   
		   cout<<res;
    return 0; 
}
