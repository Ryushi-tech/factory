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
#define pq(T) priority_queue<T, vector<T>, greater<T>>
#define fio() cin.tie(nullptr);ios::sync_with_stdio(false);
#define CEIL(a, b) (a+b-1)/b;
#define offset_FLOOR(a, b) (a-1)/b;
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<(int)v.size();i++) cerr<<" "<<v[i]; cerr<<endl
#define UNIQUE(v) v.erase(unique(all(v)), v.end());
template<class T> bool chmax(T &a, const T &b) {if (a<b) { a = b; return true; } return 0;}
template<class T> bool chmin(T &a, const T &b) {if (a>b) { a = b; return true; } return 0;}
template<class T> void print(const T &t) { cout << t << "\n"; }

ll intceil(ll a, ll b){
    if(a >= 0) return (a+b-1)/b;
    else return a/b;
}

ll intfloor(ll a, ll b){
    if(a<0) return (a-b+1)/b;
    else return a/b;
}

ll n, k;

int main() {
    fio(); cin>>n>>k;
    vl A(n); rep(i,n) cin>>A[i];
    sort(all(A));

    const ll inf = 1e18;
    ll ok = inf, ng = -inf-1;
    while(ok - ng > 1) {
        ll mid = (ok+ng)/2;
        ll num = 0;
        rep(i,n) {
            if(A[i]<0){
                ll v = intceil(-mid, -A[i]);
                num += A.begin() + i - lower_bound(A.begin(), A.begin() + i, v);
            }else if (A[i]==0) {
                if(mid>=0) num += i;
            }else {
                ll v = intfloor(mid, A[i]);
                num += upper_bound(A.begin(), A.begin() + i, v) - A.begin();
            }
        }
        (num >= k ? ok : ng) = mid;
    }
    print(ok);
}
