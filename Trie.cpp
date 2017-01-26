/*
* Link To Question : http://www.practice.geeksforgeeks.org/problem-page.php?pid=1619
* Hint : Trie Implementation
*/

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N = 20+1;

struct Trie{
    struct Trie *child[26];
    bool isLast;
};

struct Trie *getNode(){
    struct Trie * node = new Trie();
    if(node){
        for (int i = 0 ; i < 26 ; i++){
            node->child[i] = NULL;
        }
        node->isLast = 0;
    }
    return node;
}

void insert(struct Trie * root, string s){
    struct Trie * temp = root;
    for (int i = 0 ; i < s.length() ; i++){
        if(!temp->child[s[i]-'a']){
            temp->child[s[i]-'a'] = getNode();
        }
        temp = temp->child[s[i] - 'a'];
    }
    temp->isLast = 1;
}

bool search(struct Trie * root, string s){
    struct Trie * temp = root;
    for (int i = 0 ; i < s.size() ; i++){
        if(!temp->child[s[i]-'a'])  {
            return 0;
        }  
        temp = temp->child[s[i]-'a'];
    }
    return (temp!=NULL && temp->isLast);
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        struct Trie * root = getNode();
        ll n;
        cin>>n;
        for(int i = 0 ; i < n ; i ++){
            string s;
            cin>>s;
            insert(root,s);
        }
        string s;
        cin>>s;
        if(search(root,s)){
            printf("1\n");
        }else
        {
            printf("0\n");
        }
    }
}
