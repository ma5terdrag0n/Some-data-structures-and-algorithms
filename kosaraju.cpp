/*
*  Author : Pritish Thakkar aka __daemon
*  Description : The code below is STL implementatopn of kosaraju algorithm in C++ to find
*                the strongly connected graphs in a given directed graph !
*  Logic : 
*       >  REFER GEEKS FOR GEEKS FOR COMPLETE EXPLANATION

*   1) Create an empty stack ‘S’ and do DFS traversal of a graph. 
*		2) In DFS traversal, after calling recursive DFS for adjacent vertices of a vertex, push the vertex to stack. 
*		3) In the above graph, if we start DFS from vertex 0, we get vertices in stack as 1, 2, 4, 3, 0.
*		4) Reverse directions of all arcs to obtain the transpose graph.
*		5) One by one pop a vertex from S while S is not empty. Let the popped vertex be ‘v’. 
*		6) Take v as source and do DFS (call DFSUtil(v)). 
*		7) The DFS starting from v prints strongly connected component of v. 
*		8) In the above example, we process vertices in order 0, 3, 4, 2, 1 (One by one popped from stack).
*
*/
#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<n;i++)
#define inf 1000000009
#define ll long long 
#define fr first
#define sc second
using namespace std;

typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

const ll N = 1234567;
map<ll,vi> adj1,adj2;
ll color[N];

//STEP 1)
stack<ll> glass;

set<ll> s;


void dfs(ll index){
	color[index] = 1;
	for(int i = 0 ;i < adj1[index].size() ; i ++){
		ll var = adj1[index][i];
		if(!color[var]){
			dfs(var);
		}
	}
	//STEP 2)
	glass.push(index);
}


ll DDFFSS(ll index){
	color[index] = 1;
	ll ret=0;
	for(int i = 0; i < adj2[index].size() ; i ++){
		ll var = adj2[index][i];
		if(!color[var]){
			ret += DDFFSS(var);
			s.insert(var);
		}
	}
	cout<<index<<" ";
	return ret+1;
}


void solve(){
	ll t;
	cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		for(int i=0;i<m;i++){
			ll u,v;
			cin>>u>>v;
			if(u == v){
				continue;
			}
			adj1[u].pb(v);
			adj2[v].pb(u);
		}
		
		memset(color,0,sizeof color);

		for (int i=0;i<n;i++){
			if(!color[i]){
				dfs(i);
			}
		}
		
		memset(color,0,sizeof color);
		while(!glass.empty()){
			ll dima=glass.top();
			//STEP 5)
			glass.pop();
			if(!s.count(dima)){
				s.insert(dima);
				//STEP 6)
				ll h= DDFFSS(dima);
				cout<<"\n";
			}
		}
		cout<<endl;
	}
}
int main(){
	ios::sync_with_stdio(false);
	solve();
	return 0;
}

