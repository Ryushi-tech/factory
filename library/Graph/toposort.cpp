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
#define cnts(x,c) count(all(x),c)
#define fio() cin.tie(nullptr);ios::sync_with_stdio(false);
#define DEBUG_CTN(v) cerr<<#v<<":";for(auto itr=v.begin();itr!=v.end();itr++) cerr<<" "<<*itr; cerr<<endl
template<class T> bool chmax(T &a, const T &b) {if (a<b) {a = b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if (a>b) {a = b; return 1;} return 0;}
template<class T> void print(const T &t) {cout<<t<<"\n";}
template<class T> void PRINT(const T &t) {rep(i,sz(t)) cout<<t[i]<<" \n"[i==sz(t)-1];}
const ll INF = 1LL << 62;
const int iINF = 1 << 30;

#include<atcoder/all>
using namespace atcoder;

using vi = vector<int>;

vi topoSort(const vector<vi>& gr) {
    vi indeg(sz(gr)), ret;
    fore(li, gr) fore(x, li) indeg[x]++;
    queue<int> q; // use priority_queue for lexic. largest ans.
    rep(i,sz(gr)) if (indeg[i]==0) q.push(i);
    while (!q.empty()) {
        int i = q.front(); // top() for priority queue
        ret.push_back(i);
        q.pop();
        fore(x, gr[i]) if(--indeg[x] == 0) q.push(x);
    }
    return ret;
}

string T,S;
int n,m;

int main() {
    fio(); cin>>S>>T;
    string s=S;
    while(S.length()<T.length()) S+=s;
    n=sz(S);
    m=sz(T);
    auto v= z_algorithm(T+S+S);
    vector<vi> G(n);
    rep(i,n){
        if(v[i+m]<m)continue;
        G[i].emplace_back((i+m)%n);
    }
    auto tps=topoSort(G);
    if(sz(tps)!=n){
        print(-1);
        return 0;
    }
    ll ans=0;
    vl dp(n);
    fore(c,tps){
        chmax(ans,dp[c]);
        fore(t,G[c]) chmax(dp[t],dp[c]+1);
    }
    print(ans);
}
//strings of eternity