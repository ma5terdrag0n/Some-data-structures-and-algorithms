/*
*   Code By : Pritish Thakkar
*/
#include <bits/stdc++.h>
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
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef vector<ii> vi;
typedef map<ll,vv> gg;

ll ST[1000000];

void updateOnlyOne(ll *a,ll si,ll se,ll ind,ll dif,ll ss){
	if(ind < si || ind> se)
		return;
	ST[ss] += dif;
	if(si != se){
		ll mid = (si+se)>>1;
		updateOnlyOne(a,si,mid,ind,dif,2*ss+1);
		updateOnlyOne(a,mid+1,se,ind,dif,2*ss+2);
	}
}

ll getSum(ll *a,ll si,ll se,ll i1,ll i2,ll ss){
    if(si >= i1 && se <= i2)
        return ST[ss];
    if(se < i1 || si > i2)
        return 0;
    ll mid = (si+se)>>1;
    return getSum(a,si,mid,i1,i2,ss*2+1)+getSum(a,mid+1,se,i1,i2,ss*2+2);
            
    
}

void createTree(ll *a,ll s,ll e, ll ss){
    if(s>e)
        return ;
    if(s == e){
        ST[ss] = a[e];
        return;
    }
    ll mid = (s+e)>>1;
    createTree(a, s, mid,ss*2+1);
    createTree(a, mid+1,e,ss*2+2);
    ST[ss] = ST[ss*2+1]+ST[ss*2+2]; 
}

void printTree(){
	for(ll i=0;i<100;i++)
		cout<<ST[i]<< " ";
	cout<<endl;
}
int main() {
    ll n;
    cin>>n;
    ll a[n];
    ll i;
    rep(i,n)
        cin>>a[i];
    //segment tree + lazy propagation
    clr(ST);
    
    // createTree() will create a segment tree !! :-)
    
    createTree(a,0,n-1,0);
    printTree();
    // Enter 2 indices to get range sum !
    // ....
    ll ind1,ind2;
    cin>>ind1>>ind2;
    cout<<"SUM = "<<getSum(a,0,n-1,ind1,ind2,0)<<endl;
    
    // Lets update the Segment Tree !
    ll ind,val;
    cin>>ind>>val;
    ll diff = val - a[ind];
    a[ind] = val;
    updateOnlyOne(a,0,n-1,ind,diff,0);
    printTree();
    return 0;        
}
