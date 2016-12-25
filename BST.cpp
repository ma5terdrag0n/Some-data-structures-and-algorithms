/*
*  Code By : Pritish Thakkar
*  Following code contains : 
*     1. Insertion in BST
*     2. Finding height of a BST
*     3. Inorder Tree Traversal
*  Question Link : https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/practice-problems/algorithm/monk-watching-fight/
*/
#include<bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ctime>
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
#define TEST int t;cin>>t;while(t--)
using namespace std;
//.............................................

//....@typedef....................
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef vector<ii> vi;
typedef map<ll,vv> gg;
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
string toString(ll n){vector<ll>  v;while(n){v.pb(n%10);n/=10;}reverse(v.begin(),v.end());string s="";ll i;rep(i,v.size()){s.pb(v[i]+'0');}return s;}
//..........................................................................

//.................................GPFNS......................................
template <typename T>T modpow(T base,T exp, T modulus){base %= modulus;T result = 1;while (exp > 0) {if (exp & 1) result = (result * base) % modulus;base = (base * base) % modulus;exp >>= 1;}return result;}
ll gcd(ll a,ll b) {return b==0?a:gcd(b,a%b);}
ll sod(ll n){ll sum = 0;while(n){sum+=n%10;n/=10;}return sum;} // NOTE: sum of digits !!
ll binary_search(ll *a,ll start,ll end,ll toFind){
	ll mid = (start+end)>>1;
	if(start < end){if(a[mid] == toFind)return mid;else if(a[mid] < toFind)return binary_search(a,mid+1,end,toFind);else if(a[mid] > toFind)return binary_search(a,start,mid,toFind);}
	return -1;
}
//.................................................................................

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

struct node{
	ll val;
	node *left,*right;
};

node  * newNode (ll val){
	node * temp = new node();
	temp->val = val;
	temp->left = temp->right = NULL;
	return temp;
}

node * insert(ll val,node *root){
	if(root == NULL){
		return newNode(val);
	}
	if(root->val < val){
		root->right = insert(val,root->right);
	}else{
		root->left = insert(val,root->left);
	}
	return root;
}
void inorder(node * root){
	if(root == NULL){
		return ;
	}
	inorder(root->left);
	cout<<root->val<<" ";
	inorder(root->right);
}
ll ret_height(node *root){
	if(root == NULL)
		return 0;
	return 1+max(ret_height(root->left),ret_height(root->right));
}
int main(){
	ll n;
	cin>>n;
	ll a[n];
	ll i;
	node *root = NULL;
	
	rep(i,n){
		cin>>a[i];
		if(!i){
			root = insert(a[i],root);
		}
		else insert(a[i],root);
	}
	cout<<ret_height(root);
}










