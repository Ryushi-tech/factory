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

#define pq(T) priority_queue<T, vector<T>, greater<T>>
struct Edge {ll to; ll w; Edge(ll to, ll w) : to(to), w(w) {}};
using Graph = vector<vector<Edge>>;

vl dijkstra(Graph &G, int s, int g){
    int n = G.size();
    vl dist(n, INF);
    vl prev(n,-1);
    dist[s] = 0;

    using pp = pair<ll, ll>;
    pq(pp) que;
    que.push({dist[s], s});

    while (!que.empty()) {
        ll v = que.top().second;
        ll d = que.top().first;
        que.pop();

        if (d > dist[v]) continue;
        if(!G[v].empty()) fore(e, G[v]) {
            if (chmin(dist[e.to], dist[v] + e.w)) {
                prev[e.to]=v;
                que.push({dist[e.to], e.to});
            }
        }
    }
    if(dist[g]==INF){
        vl path;
        return path;
    }
    else{
        vl path;
        int c=g;
        while(c!=-1){
            path.emplace_back(c);
            c=prev[c];
        }
        reverse(all(path));
        return path;
    }
}
string st,gl,x;

int main() {
    fio(); cin>>st>>gl;
    if(st==gl) {
        print(0);
        print(st);
        print(gl);
        return 0;
    }
    map<int,string> dic;
    dic[0]=st,dic[1]=gl;
    int n,l; cin>>n; l=sz(st);
    Graph G(n+2);
    rep(i,n) {
        cin>>x; dic[i+2]=x;
    }
    rep(i,n+1) for(int j=i+1;j<n+2;j++){
        int cnt=0;
        rep(k,l) if(dic[i][k]!=dic[j][k]) cnt++;
        if(cnt==1){
            G[i].emplace_back(j,1);
            G[j].emplace_back(i,1);
        }
    }
    auto res=dijkstra(G,0,1);
    if(res.empty()) print(-1);
    else {
        print(sz(res)-2);
        fore(y,res) print(dic[y]);
    }
}
//ダブレット