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

struct Point {double x, y;};

Point operator-(const Point& a1, const Point& a2) {
    return Point{ a1.x - a2.x, a1.y - a2.y };
}

double dot(Point a, Point b){return a.x * b.x + a.y * b.y;}
double cross(Point a, Point b){return a.x * b.y - a.y * b.x;}
double angle(Point a){return atan2(a.y,a.x);}

Point rotate(Point a, double theta){
    Point rot = {sin(theta),cos(theta)};
    Point tmp = {cross(a,rot),dot(a,rot)};
    return tmp;
}

int n;
ll ei, tyo, don;
Point G[2020];

void solve(int pos) {
    vector<Point> vec;
    rep(i,n) {
        if (i == pos) continue;
        vec.push_back(G[i]-G[pos]);
    }
    sort(all(vec),[](Point a, Point b){return angle(a) < angle(b);});
    rep(i,n-1) vec.push_back(vec[i]);

    int y=0;
    rep(i,n-1){
        while(y<i+n-1 and dot(vec[i],vec[y])>=0 and cross(vec[i],vec[y])>=0) y++;
        ei += y - 1 - i;
        if(dot(vec[i],vec[y-1])==0) tyo++,ei--;
    }
}

int main() {
    cin>>n;
    don=0, tyo=0, ei=0;
    rep(i,n) cin>>G[i].x>>G[i].y;
    rep(i,n) solve(i);
    ll all = 1LL*n*(n-1)*(n-2)/6;
    don = 3*all - tyo - ei;
    ll eir = all -tyo - don;
    cout<<eir<<" "<<tyo<<" "<<don<<endl;
}
//三角形の分類