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

void merge(ll a[],ll s,ll mid,ll e);

void mergesort(ll a[],ll s,ll e){
	ll mid = s+(e-s)/2;
	if(s<e){
		mergesort(a,s,mid);
		mergesort(a,mid+1,e);
		merge(a,s,mid,e);
	}return;
}

void merge(ll *a,ll s,ll mid,ll e){
	ll i,j;
	i=s,j=mid+1;
	ll temp[e-s+10];
	ll counter=0;
	while(i<=mid && j<=e){
		if(a[i] > a[j]){
			temp[counter++] = a[j];
			j++;
		}
		else {
			temp[counter++] = a[i];
			i++;
		}
	}
	while(i<=mid){
		temp[counter++] = a[i++];
	}
	while(j<=e){
		temp[counter++] = a[j++];
	}
	ll count = 0;
	for(int i=s;i<=e;i++,count++){
		a[i] = temp[count];
	}
}

void start(){
	ll n;
	cin>>n;
	ll i;
	ll a[n];
	rep(i,n){
		cin>>a[i];
	}
	mergesort(a,0,n-1);
	rep(i,n){
		cout<<a[i]<<" ";
	}
}

int main(){
	std::ios::sync_with_stdio(0);
	start();
	return 0;
}
