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

int n, m, a, b;
int E[20];

int main() {
    fio(); cin>>n>>m;
    rep(i,m) {
        cin>>a>>b;a--;b--;
        E[a] |= 1<<b;
        E[b] |= 1<<a;
    }
    vector<int> P(1<<n,0x3fffffff);
    P[0]=1;
    rep(mask, 1<<n) rep(i,n) {
            if ((E[i] & mask) == mask and P[mask] == 1) P[mask | 1 << i] = 1;
    }
    rep(mask,1<<n) for(int sub=mask; sub>0; sub=(sub-1)&mask) {
            chmin(P[mask], P[sub]+P[sub^mask]);
        }
    print(P[(1<<n)-1]);
}
