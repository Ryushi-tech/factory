#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using vl = vector<ll>;
using vi = vector<int>;
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
template<class T> bool chmax(T &a, const T &b) {if (a<b) {a = b; return true;} return false;}
template<class T> bool chmin(T &a, const T &b) {if (a>b) {a = b; return true;} return false;}
template<class T> void print(const T &t) {cout<<t<<"\n";}
template<class T> void PRINT(const T &t) {rep(i,sz(t)) cout<<t[i]<<" \n"[i==sz(t)-1];}
const ll INF = 1LL << 62;
const int iINF = 1 << 30;

int q,n;
int A[1<<17],cnt[1<<17],ans[1<<20],L[1<<20],R[1<<20];
const int MN=1e5,B=333;
vi qs[(MN+B-1)/B];
int res=0;

void add(int id){
    if(++cnt[A[id]]%2)res++;
    else res--;
}
void rem(int id){
    if(--cnt[A[id]]%2)res++;
    else res--;
}

int main() {
    fio(); cin>>n;
    rep(i,n) cin>>A[i];
    cin>>q;
    rep(i,q){
        int l,r;cin>>l>>r;l--;
        L[i]=l;
        R[i]=r;
        qs[l/B].emplace_back(i);
    }
    int nl=0,nr=0;
    rep(i,(n+B-1)/B){
        sort(all(qs[i]),[&i](int x,int y){
            return i%2==0?R[x]<R[y]:R[x]>R[y];
        });
        fore(id,qs[i]){
            while(nl>L[id])add(--nl);
            while(nr<R[id])add(nr++);
            while(nl<L[id])rem(nl++);
            while(nr>R[id])rem(--nr);
            ans[id]=(R[id]-L[id]-res)/2;
        }
    }
    rep(i,q) print(ans[i]);
}
//RangePairingQuery