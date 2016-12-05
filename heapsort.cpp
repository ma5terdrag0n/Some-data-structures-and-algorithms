/*
*   author @Pritish Thakkar/JARVIS !
*/

// Header #include !!
#include <bits/stdc++.h>
 
//...........MACROS............................
#define min_3(a,b,c) (min((a),min((b),(c))))
#define SET(a) memset(a,-1,sizeof(a))
#define all(a) a.begin(),a.end()
#define clr(a) memset(a,0,sizeof(a))
#define FILL(a,v) memset(a,v,sizeof(a))
#define pb push_back
#define mkp make_pair
#define pi acos(-1.0)
#define inf 1000000007
#define ninf -1000000007
#define FOR(i,a,n) for(long long i=a;i<=n;i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n-1)
#define TEST int t;cin>>t;while(t--)
#define print(i) printf("%lld\n",i)
#define WHITE 0
#define BLACK 1
using namespace std;
//.............................................
 
//....@typedef....................
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
//typedef map<ll,vll> gg;
//...............................

// HEAPSORT ALGORITHM !!
// Explanation in CLRS !
void Max_heapify(ll *a,ll n,ll node){
	ll node_left = node*2;
	ll node_right = node*2+1;
	ll largest=node;
	if(node_left < n && a[node_left] > a[largest]){
			largest = node_left;
	}
	else if(node_right < n && a[node_right] > a[largest]){
		largest = node_right;	
	}
	if(largest != node){
		swap(a[node],a[largest]);
		Max_heapify(a,n,largest);
	}
	
}
	
void Sort(ll *a,ll n){
	for(int i=n/2;i>=0;i--){
		Max_heapify(a,n,i);
	}
	for(int i=n-1;i>=0;i--){
		swap(a[i],a[0]);
		Max_heapify(a,i,0);
	}
}	
void HeapSort(){
	ll n;
	cin>>n;
	ll a[n];
	ll i;
	rep(i,n){
		cin>>a[i];
	}
	Sort(a,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}

int main(){
	std::ios::sync_with_stdio(0);
    HeapSort();
	return 0;
}
