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
#define fore(i_in, a) for (auto& i_in: a)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pq(T) priority_queue<T, vector<T>, greater<T>>
#define fio() cin.tie(nullptr);ios::sync_with_stdio(false);
#define CEIL(a, b) (a+b-1)/b;
#define offset_FLOOR(a, b) (a-1)/b;
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<(int)v.size();i++) cerr<<" "<<v[i]; cerr<<endl
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
template<class T> bool chmax(T &a, const T &b) {if (a<b) { a = b; return true; } return 0;}
template<class T> bool chmin(T &a, const T &b) {if (a>b) { a = b; return true; } return 0;}
template<class T> void print(const T &t) { cout << t << "\n"; }

int n, m;
vl W; vp VL0;
ll w, l, v;

int main() {
    fio(); cin>>n>>m;
    rep(i,n) {cin>>w; W.emplace_back(w);}
    sort(all(W));
    rep(i,m) {
        cin>>l>>v;
        if (v < W.back()) {print(-1); return 0;}
        VL0.emplace_back(v, l);
    }
    sort(all(VL0));
    vp VL;
    VL.emplace_back(0, 0);
    for(auto& [v, l] : VL0){
        if(VL.size() && VL.back().second >= l) continue;
        VL.emplace_back(v, l);
    }
    ll ans=1LL<<30;

    do {
        vl dp(n), S(n + 1);
        rep(i, n) S[i + 1] = S[i] + W[i];
        rep(i, n - 1) for (int j = i + 1; j < n; j++) {
                int itr = lower_bound(all(VL), make_pair(S[j + 1] - S[i],1LL)) - VL.begin() - 1;
                ll d = VL[itr].second;
                chmax(dp[j], dp[i] + d);
            }
        chmin(ans, dp[n - 1]);
    } while (next_permutation(all(W)));
    print(ans);
}