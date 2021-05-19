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

int H,W,sx,sy,gx,gy;

int main() {
    fio(); cin>>H>>W;
    vector<string> field(H);
    cin>>sx>>sy>>gx>>gy;
    sx--;sy--;gx--;gy--;
    rep(h,H) cin>>field[h];

    vector<Graph> dist(H,Graph(W,vi(4,iINF)));
    deque<pair<pair<int, int>,int>> que;
    rep(i,4) dist[sx][sy][i]=0,que.push_back({{sx,sy},i});

    while (!que.empty()) {
        auto cur=que.front();
        int x=cur.first.first,y=cur.first.second,d=cur.second;
        que.pop_front();

        rep(dir,4) {
            int nx = x+dx[dir],ny = y+dy[dir];
            int cost = dist[x][y][d]+(dir!=d?1:0);
            if (nx<0 or nx>=H or ny<0 or ny>=W) continue;
            if (field[nx][ny]=='#') continue;
            if (chmin(dist[nx][ny][dir],cost)) {
                if(dir!=d) que.push_back({{nx,ny},dir});
                else que.push_front({{nx,ny},dir});
            }
        }
    }
    int ans=iINF;
    rep(i,4) chmin(ans,dist[gx][gy][i]);
    print(ans!=iINF?ans:-1);
}
