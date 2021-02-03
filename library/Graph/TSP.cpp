#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pl = pair<ll, ll>;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rrep1(i,n) for(int i=(n);i>0;i--)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define fore(i_in,a) for (auto& i_in: a)
#define forp(x,y,a) for(auto& [x, y]: a)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pq(T) priority_queue<T, vector<T>, greater<T>>
#define fio() cin.tie(nullptr);ios::sync_with_stdio(false);
#define ofst_FLR(a, b) (a-1)/b;
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<(int)v.size();i++) cerr<<" "<<v[i]; cerr<<endl
#define UNIQUE(v) v.erase(unique(all(v)), v.end());
template<class T> bool chmax(T &a, const T &b) {if (a<b) { a = b; return true; } return 0;}
template<class T> bool chmin(T &a, const T &b) {if (a>b) { a = b; return true; } return 0;}
template<class T> void print(const T &t) { cout << t << "\n"; }

ll n, m, k;
ll const INF = 1e11;

vl bfs(vvl adj, ll s){
    vl dist(n, INF);
    queue<ll> que;
    dist[s] = 0;
    que.push(s);
    while(!que.empty()){
        ll v = que.front(); que.pop();
        fore(to, adj[v]){
            if(dist[to] != INF) continue;
            dist[to] = dist[v] + 1;
            que.push(to);
        }
    }
    return dist;
}

int main() {
    fio(); cin>>n>>m;
    vvl E(n);
    rep(i,m) {
        ll a, b; cin>>a>>b; a--; b--;
        E[a].emplace_back(b);
        E[b].emplace_back(a);
    }
    cin>>k; vl C(k);
    rep(i,k) {cin>>C[i]; C[i]--;}
    ll k2 = 1 << k;
    vvl g(k, vl(k));

    rep(i,k) {
        vl dist = bfs(E, C[i]);
        rep(j,k) g[i][j] = dist[C[j]];
    }

    vvl dp(k2, vl(k, INF));
    rep(i,k) dp[1 << i][i] = 1;

    rep(s, k2) {
        rep(i,k) if(s >> i & 1) {
                rep(j,k) if(~s >> j & 1) {
                        chmin(dp[s|1 << j][j], dp[s][i] + g[i][j]);
                    }
            }
    }

    ll ans = *min_element(all(dp[k2 - 1]));
    print(ans == INF ? -1: ans);
}
