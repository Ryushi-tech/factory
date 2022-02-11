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

using pll=pair<ll,ll>;

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
int n;
struct dim{int u,d,l,r;};

dim rect[205];
pll ori[205];
int r[205];

double sq(double i){return i*i;}
double ctemp=5e-4;
double anneal=0.9999985;

double score=0;

double rrng(){return (double)(rng()&((1LL<<32)-1))/(1LL<<32);}

int main() {
    fio(); cin>>n;
    int a,b,c;
    rep(x,n){
        cin>>a>>b>>c;
        ori[x]={a,b};
        r[x]=c;
        rect[x]={a,a+1,b,b+1};
        score+=1-sq(1-(double)1/r[x]);
    }
    ll stime=chrono::system_clock::now().time_since_epoch().count();
    while(chrono::system_clock::now().time_since_epoch().count()-stime<4.95e9){
        int idx=rng()%n;
        int dir=rng()%4;
        int dir2=rng()%4==0;
        bool can=true;
        if(dir==0){
            if(dir2==1){
                if(rect[idx].u==ori[idx].first) continue;
            }
            else{
                if(rect[idx].u==0) continue;
                rep(x,n) if(x!=idx){
                    if(min(rect[x].d,rect[idx].d)>max(rect[x].u,rect[idx].u-1)
                       && min(rect[x].r,rect[idx].r)>max(rect[x].l,rect[idx].l)) can=false;
                }
            }
        }
        if(dir==1){
            if(dir2==1){
                if(rect[idx].d==ori[idx].first+1) continue;
            }
            else{
                if(rect[idx].d==10000) continue;
                rep(x,n) if(x!=idx){
                        if(min(rect[x].d,rect[idx].d+1)>max(rect[x].u,rect[idx].u)
                           && min(rect[x].r,rect[idx].r)>max(rect[x].l,rect[idx].l)) can=false;
                    }
            }
        }
        if(dir==2){
            if(dir2==1){
                if(rect[idx].l==ori[idx].second) continue;
            }
            else{
                if(rect[idx].l==0) continue;
                rep(x,n) if(x!=idx){
                        if(min(rect[x].d,rect[idx].d)>max(rect[x].u,rect[idx].u)
                           && min(rect[x].r,rect[idx].r)>max(rect[x].l,rect[idx].l-1)) can=false;
                    }
            }
        }
        if(dir==3){
            if(dir2==1){
                if(rect[idx].r==ori[idx].second+1) continue;
            }
            else{
                if(rect[idx].r==10000) continue;
                rep(x,n) if(x!=idx){
                        if(min(rect[x].d,rect[idx].d)>max(rect[x].u,rect[idx].u)
                           && min(rect[x].r,rect[idx].r+1)>max(rect[x].l,rect[idx].l)) can=false;
                    }
            }
        }
        if(!can) continue;
        int ai=(rect[idx].d-rect[idx].u)*(rect[idx].r-rect[idx].l);
        int af;
        if(dir2==0) af=ai+(dir<2?rect[idx].r-rect[idx].l:rect[idx].d-rect[idx].u);
        else af=ai-(dir<2?rect[idx].r-rect[idx].l:rect[idx].d-rect[idx].u);
        double ci=1-sq(1-(double)min(ai,r[idx])/max(ai,r[idx]));
        double cf=1-sq(1-(double)min(af,r[idx])/max(af,r[idx]));
        if(cf>ci || (ci-cf)*rrng()<ctemp){
            score+=cf-ci;
            if(dir==0){
                if(dir2==0) rect[idx].u--;
                else rect[idx].u++;
            }
            if(dir==1){
                if(dir2==0) rect[idx].d++;
                else rect[idx].d--;
            }
            if(dir==2){
                if(dir2==0) rect[idx].l--;
                else rect[idx].l++;
            }
            if(dir==3){
                if(dir2==0) rect[idx].r++;
                else rect[idx].r--;
            }
        }
        ctemp*=anneal;
    }
//    cerr<<score<<endl;
    rep(x,n){
        cout<<rect[x].u<<" "<<rect[x].l<<" "<<rect[x].d<<" "<<rect[x].r<<endl;
    }
}
