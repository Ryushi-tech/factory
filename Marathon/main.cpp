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

//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937 rng(12345);

int n,m;
int g[33][33],cnt[11],flg[11];
string s[21];
struct animal{int x,y,t;};
animal anim[21];
struct person{int x,y,t;};
person psn[11],tmp[11];
string res;

void mvl(int cx,int cy,int i){
    if(cy==0 or g[cx][cy-1]==1) res+='.';
    else res+='L',psn[i].y--;
}

void mvr(int cx,int cy,int i){
    if(cy==29 or g[cx][cy+1]==1) res+='.';
    else res+='R',psn[i].y++;
}

void mvu(int cx,int cy,int i){
    if(cx==0 or g[cx-1][cy]==1) res+='.';
    else res+='U',psn[i].x--;
}

void mvd(int cx,int cy,int i){
    if(cx==29 or g[cx+1][cy]==1) res+='.';
    else res+='D',psn[i].x++;
}

void bkl(int cx,int cy){
    bool flg=true;
    if(cy==0 or g[cx][cy-1]==1) flg=false;
    rep(j,m){
        if(psn[j].x==cx and psn[j].y==cy-1) flg=false;
        if(tmp[j].x==cx and tmp[j].y==cy-1) flg=false;
    }
    rep(j,n){
        if(anim[j].x==cx and anim[j].y==cy) flg=false;
        if(anim[j].x==cx and anim[j].y==cy-1) flg=false;
        if(cy-2<=29 and anim[j].x==cx and anim[j].y==cy-2) flg=false;
        if(cx-1>=0 and anim[j].x==cx-1 and anim[j].y==cy-1) flg=false;
        if(cx+1<=29 and anim[j].x==cx+1 and anim[j].y==cy-1) flg=false;
    }
    if(!flg) res+='.';
    else res+='l',g[cx][cy-1]=1;
}

void bkr(int cx,int cy){
    bool flg=true;
    if(cy==29 or g[cx][cy+1]==1) flg=false;
    rep(j,m){
        if(psn[j].x==cx and psn[j].y==cy+1) flg=false;
        if(tmp[j].x==cx and tmp[j].y==cy+1) flg=false;
    }
    rep(j,n){
        if(anim[j].x==cx and anim[j].y==cy) flg=false;
        if(anim[j].x==cx and anim[j].y==cy+1) flg=false;
        if(cy+2<=29 and anim[j].x==cx and anim[j].y==cy+2) flg=false;
        if(cx-1>=0 and anim[j].x==cx-1 and anim[j].y==cy+1) flg=false;
        if(cx+1<=29 and anim[j].x==cx+1 and anim[j].y==cy+1) flg=false;
    }
    if(!flg) res+='.';
    else res+='r',g[cx][cy+1]=1;
}

void bku(int cx,int cy){
    bool flg=true;
    if(cx==0 or g[cx-1][cy]==1) flg=false;
    rep(j,m){
        if(psn[j].x==cx-1 and psn[j].y==cy) flg=false;
        if(tmp[j].x==cx-1 and tmp[j].y==cy) flg=false;
    }
    rep(j,n){
        if(anim[j].x==cx and anim[j].y==cy) flg=false;
        if(anim[j].x==cx-1 and anim[j].y==cy) flg=false;
        if(cx-2>=0 and anim[j].x==cx-2 and anim[j].y==cy) flg=false;
        if(cy-1>=0 and anim[j].x==cx-1 and anim[j].y==cy-1) flg=false;
        if(cy+1<=29 and anim[j].x==cx-1 and anim[j].y==cy+1) flg=false;
    }
    if(!flg) res+='.';
    else res+='u',g[cx-1][cy]=1;
}

void bkd(int cx,int cy){
    bool flg=true;
    if(cx==29 or g[cx+1][cy]==1) flg=false;
    rep(j,m){
        if(psn[j].x==cx+1 and psn[j].y==cy) flg=false;
        if(tmp[j].x==cx+1 and tmp[j].y==cy) flg=false;
    }
    rep(j,n){
        if(anim[j].x==cx and anim[j].y==cy) flg=false;
        if(anim[j].x==cx+1 and anim[j].y==cy) flg=false;
        if(cx+2<=29 and anim[j].x==cx+2 and anim[j].y==cy) flg=false;
        if(cy-1>=0 and anim[j].x==cx+1 and anim[j].y==cy-1) flg=false;
        if(cy+1<=29 and anim[j].x==cx+1 and anim[j].y==cy+1) flg=false;
    }
    if(!flg) res+='.';
    else res+='d',g[cx+1][cy]=1;
}

int main() {
    fio(); cin>>n;
    rep(i,n){
        int x,y,t; cin>>x>>y>>t; x--;y--;
        anim[i]={x,y,t};
    }
    cin>>m;
    rep(i,m){
        int x,y,t; cin>>x>>y; x--;y--;
        if(x<15 and y<15) t=0;
        else if(x<15 and 15<=y) t=1;
        else if(15<=x and 15<=y) t=2;
        else t=3;
        psn[i]={x,y,t};
    }
    rep(i,n) s[i]=" ";
    int d=5;
    rep(_,300){
        rep(i,m) tmp[i]=psn[i];
        rep(i,n) fore(c,s[i]){
            if(c=='L') anim[i].y--;
            if(c=='R') anim[i].y++;
            if(c=='U') anim[i].x--;
            if(c=='D') anim[i].x++;
        }
        res="";
        memset(cnt,0,sizeof(cnt));
        rep(i,n) cnt[(anim[i].x)/d]++;
        int itv=51;
        int itv2=61;
        int itv3=71;
        int itv4=81;
        int itv5=91;
        rep(i,m){
//            unsigned int rnd=rng();
            int cx=psn[i].x;
            int cy=psn[i].y;
//            int ct=psn[i].t;
            if(_<itv){
                if(cy>0) mvl(cx,cy,i);
                else if(cx<5*(i%5+1)-1) mvd(cx,cy,i);
                else if(cx>5*(i%5+1)-1) mvu(cx,cy,i);
                else res+='.';
            } else {
                if(cy==0 and i%5==0) mvr(cx,cy,i);
                else if(cy==0 and i%5==1 and itv2<_) mvr(cx,cy,i);
                else if(cy==0 and i%5==2 and itv3<_) mvr(cx,cy,i);
                else if(cy==0 and i%5==3 and itv4<_) mvr(cx,cy,i);
                else if(cy==0 and i%5==4 and itv5<_) mvr(cx,cy,i);
                else if(g[cx][cy-1]==0) bkl(cx,cy);
                else if(cy==29) {
                    if(g[cx-1][cy]==1 or g[cx+1][cy]==1) res+='.';
                    else if(cnt[i%5]>cnt[i%5+1]) bku(cx,cy);
                    else bkd(cx,cy);
                }
                else if(g[cx][cy-1]==1) mvr(cx,cy,i);
                else res+='.';
            }
        }
        cout<<res<<endl;
        rep(i,n) cin>>s[i];
    }
}