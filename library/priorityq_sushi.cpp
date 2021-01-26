#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pl = pair<ll, ll>;
using ml = map<ll, ll>;
using vl = vector<ll>;
using vp = vector<pl>;
using vvl = vector<vl>;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(n);i>0;i--)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define fore(i_in,a) for (auto& i_in: a)
#define forp(x,y,a) for(auto& [x, y]: a)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pq(T) priority_queue<T, vector<T>>
#define fio() cin.tie(nullptr);ios::sync_with_stdio(false);
#define CEIL(a, b) (a+b-1)/b;
#define offset_FLOOR(a, b) (a-1)/b;
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<(int)v.size();i++) cerr<<" "<<v[i]; cerr<<endl
#define UNIQUE(v) v.erase(unique(all(v)), v.end());
template<class T> bool chmax(T &a, const T &b) {if (a<b) { a = b; return true; } return 0;}
template<class T> bool chmin(T &a, const T &b) {if (a>b) { a = b; return true; } return 0;}
template<class T> void print(const T &t) { cout << t << "\n"; }

ll n, k, t, d;
const ll inf = 1LL<<40;

int main() {
    fio(); cin>>n>>k;
    vvl sushi(n);
    rep(i,n) {
        cin>>t>>d;t--;
        sushi[t].emplace_back(d);
    }
    fore(v, sushi) {
        sort(rall(v));
        if(v.empty()) v.emplace_back(-inf);
    }
    sort(all(sushi), [&](vl a, vl b) {return a[0] > b[0];});

    pq(ll) que; ll cur=0;
    rep(i,k) {
        cur += sushi[i][0];
        rep1(j,sushi[i].size()-1) que.push(sushi[i][j]);
    }
    for(int i = k; i<n ; i++) rep(j,sushi[i].size()) que.push(sushi[i][j]);
    ll res = cur + k*k;
    for(ll x=k-1; x>=1; x--) {
        ll v = sushi[x][0];
        ll w = que.top();
        if(v < w) {
            que.pop(); cur += w;
            que.push(v); cur -= v;
        }
        chmax(res, cur + x*x);
    }
    print(res);
}
