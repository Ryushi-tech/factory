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

int nth_bit(ll num, int n) {return (num>>n)&1;}

ll msb(ll v){
    v = v|(v>>1);
    v = v|(v>>2);
    v = v|(v>>4);
    v = v|(v>>8);
    v = v|(v>>16);
    v = v|(v>>32);
    return v^(v>>1);
}

int n;

int main() {
    fio(); cin>>n;
    vl a(n); rep(i,n) cin>>a[i];
    ll ans1=0;
    rep(d,60) {
        int num=0;
        fore(x,a) num+=nth_bit(x,d);
        if(num%2){
            ans1+=1LL<<d;
            fore(x,a) if(nth_bit(x,d)) x^=1LL<<d;
        }
    }
    vl V;
    fore(x,a){
        fore(v,V) if(msb(v)&x) x^=v;
        if(x>0){
            fore(v,V) if(msb(x)&v) v^=x;
            V.emplace_back(x);
            sort(rall(V));
        }
    }
    ll ans2=0;
    fore(v,V) ans2^=v;
    ll ans=ans1+2*ans2;
    print(ans);
}
//Xor Sum 3