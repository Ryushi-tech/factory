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

template<class T>
struct point{
    T x,y;
    point &operator+=(const point &a){ x+=a.x; y+=a.y; }
    point &operator-=(const point &a){ x-=a.x; y-=a.y; }
    point operator+(const point &a)const{ return (point){x+a.x,y+a.y}; }
    point operator-(const point &a)const{ return (point){x-a.x,y-a.y}; }
    operator point<double>()const{ return (point<double>){x,y}; }
};
template<class T>
struct segment{
    point<T> a,b;
    operator segment<double>()const{ return (segment<double>){a,b}; }
};
template<class T>
T cross(const point<T> &a,const point<T> &b){ return a.x*b.y-a.y*b.x; }
enum{CCW=1,CW=-1,ON=0};
template<class T>
int ccw(const point<T> &a,const point<T> &b,const point<T> &c){
    T rdir=cross(b-a,c-a);
    if(rdir>0) return CCW;
    if(rdir<0) return CW;
    return ON;
}
template<class T>
bool intersect(const segment<T> &S1,const segment<T> &S2){
    if(max(S1.a.x,S1.b.x)<min(S2.a.x,S2.b.x)
       || max(S1.a.y,S1.b.y)<min(S2.a.y,S2.b.y)
       || max(S2.a.x,S2.b.x)<min(S1.a.x,S1.b.x)
       || max(S2.a.y,S2.b.y)<min(S1.a.y,S1.b.y)) return false;
    return ccw(S1.a,S1.b,S2.a)*ccw(S1.a,S1.b,S2.b)<=0
           && ccw(S2.a,S2.b,S1.a)*ccw(S2.a,S2.b,S1.b)<=0;
}
int main()
{
    int ax,ay,bx,by;
    cin>>ax>>ay>>bx>>by;
    point<int> a={ax,ay};
    point<int> b={bx,by};
    segment<int> ab={a,b};
    int n;
    cin>>n;
    int cnt=0;
    point<int> p[n];
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        p[i].x=x;
        p[i].y=y;
    }
    for(int i=0;i<n-1;i++)
    {
        segment<int> tmp={p[i],p[i+1]};
        if(intersect(ab,tmp))
        {
            cnt++;
        }
    }
    segment<int> tmp={p[n-1],p[0]};
    if(intersect(ab,tmp))
    {
        cnt++;
    }
    cout<<(cnt/2)+1<<endl;
}