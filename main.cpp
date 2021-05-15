#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rrep1(i,n) for(int i=(n);i>0;i--)
#define fore(i_in,a) for (auto& i_in: a)
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fio() cin.tie(nullptr);ios::sync_with_stdio(false);
#define DEBUG_CTN(v) cerr<<#v<<":";for(auto itr=v.begin();itr!=v.end();itr++) cerr<<" "<<*itr; cerr<<endl
template<class T> bool chmax(T &a, const T &b) {if (a<b) { a = b; return true; } return false;}
template<class T> bool chmin(T &a, const T &b) {if (a>b) { a = b; return true; } return false;}
template<class T> void print(const T &t) { cout << t << "\n"; }
const ll INF = 1LL << 62;
const int iINF = 1 << 30;

int max_num=30;
ll ans=1,way=0;
using vi = vector<int>;
using Graph = vector<vi>;

Graph G(max_num);
vi seen(max_num),color(max_num),v;

void dfs(int idx) {
    if(idx==sz(v)) {way++; return;}
    set<int> st;
    st.insert(1);
    st.insert(2);
    st.insert(3);
    fore(nv, G[v[idx]]) {
        st.erase(color[nv]);
    }
    fore(c,st){
        color[v[idx]]=c;
        dfs(idx+1);
        color[v[idx]]=0;
    }
}

void dfs2(int now){
    v.emplace_back(now);
    seen[now]=1;
    fore(to,G[now]){
        if(seen[to]!=0) continue;
        dfs2(to);
    }
}

int n,m,a,b;

int main() {
    fio(); cin>>n>>m;
    rep(i,m) {
        cin>>a>>b;a--;b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    rep(i,n) {
        if(seen[i]!=0) continue;
        v.resize(0);
        dfs2(i);
        way=0;
        dfs(0);
        ans*=way;
    }
    print(ans);
}
//RGB Coloring2