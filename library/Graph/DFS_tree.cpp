#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;

#define rep(i,n) for (int i=0;i<(int)(n);i++)
template<class T> void print(const T& t){cout<<t<<"\n"; }

int max_num=101010;
using Graph=vector<vi>;
Graph G(max_num);
vi depth(max_num), subtree_size(max_num), cnt(max_num), color(max_num);
vector<bool> good(max_num);

void dfs(int v,int p=-1,int d=0) {
    if(cnt[color[v]]==0) good[v]=true;
    cnt[color[v]]++;
    depth[v]=d;
    subtree_size[v]=1;
    fore(nv,G[v]) {
        if(nv==p) continue;
        dfs(nv,v,d+1);
        subtree_size[v]+=subtree_size[nv];
    }
    cnt[color[v]]--;
}

int n,a,b;

int main() {
    fio(); cin>>n;
    rep(i,n) cin>>color[i];
    rep(i,n-1) {
        cin>>a>>b;a--;b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    dfs(0);
    rep(i,n) if(good[i]) print(i+1);
}
//unique color