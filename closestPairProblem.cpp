/*
*  Author : Pritish Thakkar
*  This is using line sweep algorithm
*  For divide and conquer algorithm visit : Algorithm / Divide and conquer / Math / Closest Pair
*/
 
#include<bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ctime>
#define fr first
#define sec second
#define SET(a) memset(a,-1,sizeof(a))
#define all(a) a.begin(),a.end()
#define clr(a) memset(a,0,sizeof(a))
#define FILL(a,v) memset(a,v,sizeof(a))
#define pb push_back
#define mkp make_pair
#define pi acos(-1.0)
#define inf 1000000009
#define ninf -1000000007
#define FOR(i,a,n) for(long long i=a;i<=n;i++)
#define fre \
	freopen("drstrange.txt","r",stdin);\
	freopen("batman.txt","w",stdout);
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n-1)
#define dead(i,s,n) for(long long i=s;i>=n;i--)
#define dec(i,s) dead(i,s,0LL)
#define TEST int t;cin>>t;while(t--)
using namespace std;
//.............................................
 
//....@typedef....................
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
//...............................
 
//.............Translator.................................................
bool isUpperCase(char c){return c>='A' && c<='Z';}//NOTES:isUpperCase
bool isLowerCase(char c){return c>='a' && c<='z';}//NOTES:isLowerCase
bool isLetter(char c){return c>='A' && c<='Z' || c>='a' && c<='z';}//NOTES:isLetter
bool isDigit(char c){return c>='0' && c<='9';}//NOTES:isDigit
char toLowerCase(char c){return (isUpperCase(c))?(c+32):c;}//NOTES:toLowerCase
char toUpperCase(char c){return (isLowerCase(c))?(c-32):c;}//NOTES:toUpperCase
bool isAlpha(char c){return isUpperCase(c)||isLowerCase(c);}//NOTES:isaplhabet or not
//NOTE : long long to string
string toString(ll n){
	vector<ll>  v;
	while(n){
		v.pb(n%10);
		n/=10;
	}
	reverse(v.begin(),v.end());
	string s="";
	ll i;rep(i,v.size()){s.pb(v[i]+'0');}
	return s;
}
//..........................................................................
 
//.................................GPFNS......................................
template <typename T>T modpow(T base,T exp, T modulus){
	base %= modulus;
	T result = 1;
	while (exp > 0) {
		if (exp & 1) result = (result * base) % modulus;
		base = (base * base) % modulus;exp >>= 1;
	}
	return result;
}
ll gcd(ll a,ll b) {return b==0?a:gcd(b,a%b);}
ll sod(ll n){ll sum = 0;while(n){sum+=n%10;n/=10;}return sum;} // NOTE: sum of digits !!
ll binary_search(ll *a,ll start,ll end,ll toFind){
	ll mid = (start+end)/2;
	if(start < end){
		if(a[mid] == toFind)
			return mid;
		else if(a[mid] < toFind)
			return binary_search(a,mid+1,end,toFind);
		else if(a[mid] > toFind)return binary_search(a,start,mid,toFind);
	}
	return -1;
}
//..................Eratosthenes Sieve........................................
 
 ll sieve_size;
 bitset <1000010> bs;
 vector<ll> primes;
 void sieve(ll upperbound){
 sieve_size=upperbound+1;
 bs.reset(),bs.flip();//set all nos. to 1
 bs.set(0,false);bs.set(1,false);//except 0 ans 1
 for(ll i=2;i<=sieve_size;i++){
     if(bs.test((size_t)i)){
         for(ll j=i*i;j<=sieve_size;j+=i){
             bs.set((size_t)j,false);
         }
         primes.push_back((ll)i);
         }
     }
 }
//-----------------------Data Type for defining a point---------------------
struct point{
	ll x,y;
};
//-------------------------AREA FOR SOLVEING PROBLEM------------------------------

ll compx(ii a, ii b){
	return a.sec < b.sec;
}
 
void solve(){
	ll n;
	while(cin >> n , n){
		vii v;
		for( int  i = 0 ; i < n ; i++){
			ll x , y ;
			cin >> x >> y;
			v.pb(mkp ( y, x));
		}
		sort(v.begin(),v.end(),compx);
		double best = inf;
		set<ii> s;
		s.insert(v[0]);
		ll i,left=0;
		FOR(i,1,n-1){
			while(left < i && v[i].sec - v[left].sec > best ){
				s.erase(v[left]);
				left++;
			}
			for(set<ii>::iterator it = s.lower_bound(mkp ( v[i].fr - best, v[i].sec - best)) ; it != s.end()\
				&& it->fr <= v[i].fr + best ; it++ ){
				ll x,y;
				x = it->sec;
				y = it->fr;
				double dist = 1.00 * sqrt((v[i].fr - y) * (v[i].fr - y) +  (v[i].sec - x) * (v[i].sec - x) );
				if(dist < best){
					best = dist;
				}
			}
			s.insert(v[i]);
		}
		printf("%.04f\n",best);
	}
}
//-----------Stay Away from main()----------------------------
 
int main(){	
	std::ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	solve();
	return 0;
}
 
