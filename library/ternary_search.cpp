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
template<class T> bool chmax(T &a, const T &b) {if (a<b) {a = b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if (a>b) {a = b; return 1;} return 0;}
template<class T> void print(const T &t) {cout << t << "\n";}
const ll INF = 1LL << 62;
const int iINF = 1 << 30;
const double eps=1e-7;

int n;
using vi = vector<int>;

double check(vi& a,double x){
    double res=0.0;
    fore(y,a) res+=x+(double)y-min((double)y,2*x);
    return res;
}

int main() {
    fio(); cin>>n;
    vi a(n); rep(i,n) cin>>a[i];
    double l=0,r=1e10;
    while(l+eps<r){
        double c1=l+(r-l)/3;
        double c2=r-(r-l)/3;
        if(check(a,c1)+eps<check(a,c2)) r=c2;
        else l=c1;
    }
    auto ans=check(a,l)/n;
    cout << fixed << setprecision(6) << ans << "\n";
}
//insurance