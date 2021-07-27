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

using vi = vector<int>;
using pii = pair<int,int>;

const int LIM = 1e6;
bitset<LIM> isPrime;
vi eratosthenes() {
    const int S = (int)round(sqrt(LIM)), R = LIM/2;
    vi pr = {2}, sieve(S+1); pr.reserve(int(LIM/log(LIM)*1.1));
    vector<pii> cp;
    for (int i=3; i<=S; i+=2) if (!sieve[i]) {
            cp.push_back({i, i*i/2});
            for (int j=i*i; j<=S; j+=2*i) sieve[j] = 1;
        }
    for (int L=1; L<=R; L+=S) {
        array<bool, S> block{};
        for (auto &[p, idx] : cp)
            for (int i=idx; i<S+L; idx = (i+=p)) block[i-L] = 1;
        rep(i,min(S, R-L))
        if (!block[i]) pr.push_back((L+i)*2+1);
    }
    fore(i,pr) isPrime[i]=1;
    return pr;
}

ll l,r;

int main() {
    fio(); cin>>l>>r;
    auto pr=eratosthenes();
    ll ans=0;
    fore(x,pr){
        if(x<l) continue;
        if(x>r) break;
        ans+=(r/x-1)*(x-1);
    }
    print(ans);
}
