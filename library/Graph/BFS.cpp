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

using Graph = vector<vector<int>>;

vector<int> BFS(const Graph &G, int s) {
    int n = sz(G);
    vector<int> dist(n,-1);
    queue<int> que;

    dist[s]=0;
    que.push(s);

    while(!que.empty()) {
        int v=que.front();
        que.pop();
        fore(nv,G[v]) {
            if (dist[nv]!=-1) continue;
            dist[nv]=dist[v]+1;
            que.push(nv);
        }
    }
    return dist;
}

int main() {
    int n,m;
    cin>>n>>m;

    Graph G(n);
    rep(i,m) {
        int a,b;a--;b--;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> dist=BFS(G,0);
    rep(i,n) print(dist[i]);
}