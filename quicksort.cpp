/*
*   author @Pritish Thakkar/JARVIS !
http://www.spoj.com/problems/EBOXES/
*/
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
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpl;
//typedef map<ll,vll> gg;
//...............................

ll partition(ll a[],ll s,ll e);

void quicksort(ll a[],ll s,ll e){
	if(s<e){
		ll p=partition(a,s,e);
		quicksort(a,s,p-1);
		quicksort(a,p+1,e);
	}return;
}

ll partition(ll *a,ll s,ll e){
	ll pivot = a[e];
	ll i=s-1;
	for(int j=s;j<e;j++){
		if(a[j] <= pivot){
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[e]);
	return i+1;
}

void start(){
  cout<<"ENTER N\t";
	ll n;
	cin>>n;
	ll i;
  cout<<"ENTER ELEMENTS\n";
	ll a[n];
	rep(i,n){
		cin>>a[i];
	}
	quicksort(a,0,n-1);
  cout<<"SORTED ARRAY\n";
	rep(i,n){
		cout<<a[i]<<" ";
	}
}

int main(){
	std::ios::sync_with_stdio(0);
	start();
	return 0;
}
