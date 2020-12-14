#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

#define rep(i, n) for (int i = 0; i < (int) (n); i++)
template<class T> void print(const T& t){ cout << t << "\n"; }

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int main() {
    int H, W; cin >> H >> W;
    vector<string> field(H);
    rep(h, H) cin >> field[h];

    int sx, sy, gx, gy;
    rep(h, H) {
        rep(w, W) {
            if (field[h][w] == 'S') {
                sx = h; sy = w;
            }
            if (field[h][w] == 'G') {
                gx = h; gy = w;
            }
        }
    }

    Graph dist(H, vector<int>(W, -1));
    dist[sx][sy] = 0;
    queue<pair<int, int> > que;
    que.push(make_pair(sx, sy));

    while (!que.empty()) {
        pair<int, int> cur = que.front();
        int x = cur.first;
        int y = cur.second;
        que.pop();

        rep(dir, 4) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (field[nx][ny] == '#') continue;
            if (dist[nx][ny] == -1) {
                que.push(make_pair(nx, ny));
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
    }
    print(dist[gx][gy]);
}
