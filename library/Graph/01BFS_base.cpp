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

using vi = vector<int>;
using Graph = vector<vi>;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
const int wx[20] = {2,2,2,1,0,-1,-2,-2,-2,1,0,-1,1,1,0,-1,-1,0,1,-1};
const int wy[20] = {1,0,-1,2,2,2,1,0,-1,-2,-2,-2,1,0,1,-1,0,-1,-1,1};

int H,W;

int main() {
    fio(); cin>>H>>W;
    vector<string> field(H);
    rep(h,H) cin>>field[h];

    Graph dist(H,vi(W,iINF));
    deque<pair<int, int>> que;
    dist[0][0]=0;
    que.emplace_back(0,0);

    while (!que.empty()) {
        auto cur=que.front();
        int x=cur.first,y=cur.second;
        que.pop_front();

        rep(dir,4) {
            int nx=x+dx[dir],ny=y+dy[dir];
            if (nx<0 or nx>=H or ny<0 or ny>=W) continue;
            if (field[nx][ny]=='#') continue;
            if (chmin(dist[nx][ny],dist[x][y])) que.emplace_front(nx,ny);
        }
        rep(dir,20) {
            int nx=x+wx[dir],ny=y+wy[dir];
            if (nx<0 or nx>=H or ny<0 or ny>=W) continue;
            if (chmin(dist[nx][ny],dist[x][y]+1)) que.emplace_back(nx,ny);
        }
    }
    print(dist[H-1][W-1]);
}
//stronger takahashi