#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,b) for(int i = 0; i < b; i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fio() cin.tie(nullptr); ios::sync_with_stdio(false)
template<class T> void chmax(T &t, const T s) {if (t < s) t = s;}
template<class T> void chmin(T &t, const T s) {if (t > s) t = s;}
template<class T> void print(const T &t) {cout << t << "\n";}

using vi = vector<int>;
using Graph = vector<vi>;
int n, t;
vi sz, dp;

void dfs(Graph &E, int v) {
    int neg = 0;
    vi seq;
    for(auto &to: E[v]){
        dfs(E, to);
        sz[v] += sz[to];
        if(sz[to]&1) {
            seq.emplace_back(-dp[to]);
        }else{
            if(dp[to]<0){
                dp[v] -= -dp[to];
            }else neg += -dp[to];
        }
    }
    sort(rall(seq));
    seq.emplace_back(neg);

    for(int i=0; i<(int)seq.size(); i++){
        if(i&1) dp[v] += seq[i];
        else dp[v] -= seq[i];
    }
};

int main() {
    fio(); cin>>n;
    Graph E(n);
    rep(i,n-1) {
        cin>>t; t--;
        E[t].emplace_back(i+1);
    }

    sz.assign(n,1);
    dp.assign(n,1);

    dfs(E,0);
    print((n+dp[0])/2);
}