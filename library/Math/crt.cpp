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

using pll = pair<ll,ll>;

ll extgcd(ll a, ll b, ll &x, ll &y){
    if(b == 0){
        x = 1, y = 0;
        return a;
    }
    ll xx, yy;
    ll d = extgcd(b, a%b, xx, yy);
    x = yy, y = xx-(a/b)*yy;
    return d;
}

ll mod_inverse(ll a, ll m){
    ll x, y;
    if(extgcd(a, m, x, y) != 1) return -1;
    return (x%m + m) % m;
}

pll congruence(ll a, ll b, ll m){
    ll d = gcd(a, m);
    if(b % d) return make_pair(0, -1);
    a /= d, b /= d, m /= d;
    return make_pair(b * mod_inverse(a,m) % m, m);
}

pll CRT(vl a, vl b, vl m){
    ll x = 0, M = 1;
    assert(sz(a) == sz(b) and sz(a) == sz(m));
    int t = sz(a);
    rep(i,t){
        pll res = congruence(a[i]*M, (b[i]-a[i]*x%m[i]+m[i])%m[i], m[i]);
        if(res.second == -1) return res;
        x += M*res.first, M *= res.second;
    }
    return make_pair(x,M);
}

ll n,m,k,c;
vl a(5e5+500), b(5e5+500), p(1e6+100), q(1e6+100);
vector<pll> res(1e6+100);

bool check(ll x){
    ll sum = 0;
    rep1(i,c){
            if(res[i].second == -1) continue;
            sum += x / res[i].second;
            if(res[i].first < x % res[i].second) sum++;
    }
    return x - sum >= k;
}

int main() {
    fio(); cin>>n>>m>>k;
    rep1(i,n) {cin>>a[i]; p[a[i]]=i;}
    rep1(i,m) {cin>>b[i]; q[b[i]]=i;}

    vl a={1,1}, M={n,m};
    c = 2*max(n,m);
    rep1(i,c) {
        if(p[i] == 0 || q[i] == 0){
            res[i].second = -1;
            continue;
        }
        vl b = {p[i]%n-1, q[i]%m-1};
        res[i] = CRT(a, b, M);
    }

    ll ub = INF, lb = 0, mid;
    while(ub-lb>1){
        mid = (ub+lb)/2;
        if(check(mid)) ub = mid;
        else lb = mid;
    }
    print(ub);
}

//https://codeforces.com/contest/1500/problem/B