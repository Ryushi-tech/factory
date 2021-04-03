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
template<class T> bool chmax(T &a, const T &b) {if (a<b) { a = b; return true; } return 0;}
template<class T> bool chmin(T &a, const T &b) {if (a>b) { a = b; return true; } return 0;}
template<class T> void print(const T &t) { cout << t << "\n"; }
const ll INF = 1LL << 62;
const int iINF = 1 << 30;

int q;
ll n,a,b,c,d;
using pll = pair<ll,ll>;

int main() {
    fio(); cin>>q;
    while(q--){
        cin>>n>>a>>b>>c>>d;
        vl cost(6);cost[2]=a;cost[3]=b;cost[5]=c;
        priority_queue<pll,vector<pll>,greater<pll>> que;
        map<ll,ll> memo;
        ll ans = INF;

        auto insert = [&](ll v, ll m){
            if(v < ans and (!memo.count(m) or v < memo[m])) {
                que.emplace(v,m);
                memo[m] = v;
            }
        };

        que.emplace(0,n);
        while(!que.empty()){
            auto [v, m] = que.top(); que.pop();
            if(v >= ans) break;
            if(m <= INF/d) chmin(ans, v+m*d);
            vector<int> cnd = {2,3,5};
            fore(x, cnd) {
                int r = m%x;
                ll v2 = v + r*d + cost[x];
                insert(v2,m/x);
                v2 = v + (x-r)*d + cost[x];
                insert(v2,m/x+1);
            }
        }
        print(ans);
    }
}
