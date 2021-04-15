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
template<class T> bool chmax(T &a, const T &b) {if (a<b) { a = b; return true; } return false;}
template<class T> bool chmin(T &a, const T &b) {if (a>b) { a = b; return true; } return false;}
template<class T> void print(const T &t) { cout << t << "\n"; }
const ll INF = 1LL << 62;
const int iINF = 1 << 30;

class BIT{
public:
    ll n; vector<ll> a;
    BIT(ll n):n(n),a(n+1,0){}

    void add(ll i,ll x){
        i++; if(i==0) return;
        for(ll k=i;k<=n;k+=(k&-k)) a[k]+=x;
    }

    ll sum(ll i,ll j) {return sum_sub(j)-sum_sub(i-1);}

    ll sum_sub(ll i){
        i++; ll s=0; if(i==0) return s;
        for(ll k=i;k>0;k-=(k&-k)) s+=a[k];
        return s;
    }

    ll lower_bound(ll x){
        int sum=0, pos=0, ts=1, LOGN=0;
        while(ts < n) {ts<<=1; LOGN++;}
        rrep(i,LOGN) if(pos+(1<<i) < n and sum+a[pos+(1<<i)] < x) {
                sum += a[pos+(1<<i)];
                pos += (1<<i);
        }
        return pos;
    }
};

int n;
using vi = vector<int>;

int main() {
    fio(); cin>>n;
    vi p(n), pos(n+1);
    rep(i,n) {cin>>p[i]; pos[p[i]]=i;}
    BIT fw(n+1);
    ll ans=0;
    rrep1(i,n){
        fw.add(pos[i],1);
        int s = fw.sum_sub(pos[i]);
        vi bound;
        vi dif = {-2,-1,1,2};
        fore(x, dif){
            if(s+x<=0) {bound.emplace_back(-1); continue;}
            int ok=fw.lower_bound(s+x);
            bound.emplace_back(ok);
        }
        ll num = (bound[1]-bound[0])*(bound[2]-pos[i])+(pos[i]-bound[1])*(bound[3]-bound[2]);
        ans += i*num;
    }
    print(ans);
}
//Second sum