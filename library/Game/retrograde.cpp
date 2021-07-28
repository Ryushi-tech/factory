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
#define cnts(x,c) count(all(x),c)
#define fio() cin.tie(nullptr);ios::sync_with_stdio(false);
#define DEBUG_CTN(v) cerr<<#v<<":";for(auto itr=v.begin();itr!=v.end();itr++) cerr<<" "<<*itr; cerr<<endl
template<class T> bool chmax(T &a, const T &b) {if (a<b) {a = b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if (a>b) {a = b; return 1;} return 0;}
template<class T> void print(const T &t) {cout<<t<<"\n";}
template<class T> void PRINT(const T &t) {rep(i,sz(t)) cout<<t[i]<<" \n"[i==sz(t)-1];}
const ll INF = 1LL << 62;
const int iINF = 1 << 30;

int m=52*52*52;

int chr2int(char c){
    if('A'<=c and c<='Z') return c-'A';
    else return c-'a'+26;
}

int str2int(char a,char b,char c){
    return chr2int(a)*52*52+chr2int(b)*52+ chr2int(c);
}

int n;
string s;
using vi = vector<int>;
using pii = pair<int,int>;

int main() {
    fio(); cin>>n;
    vector<pii> edge(n);
    vector<vi> revGraph(m);
    vi cnt(m);
    rep(i,n){
        cin>>s;
        edge[i]={str2int(s[0],s[1],s[2]), str2int(s[sz(s)-3],s[sz(s)-2],s[sz(s)-1])};
        cnt[edge[i].first]++;
        revGraph[edge[i].second].emplace_back(edge[i].first);
    }
    vi ans(m,-1);
    queue<int> que;
    rep(i,m) if(cnt[i]==0){
        ans[i]=0;
        que.push(i);
    }
    while(!que.empty()){
        int t=que.front(); que.pop();
        fore(x,revGraph[t]) if(ans[x]==-1){
            cnt[x]--;
            if(ans[t]==0){
                ans[x]=1;que.push(x);
            }
            else if(cnt[x]==0){
                ans[x]=0;que.push(x);
            }
        }
    }
    rep(i,n){
        if(ans[edge[i].second]==-1) print("Draw");
        if(ans[edge[i].second]==0) print("Takahashi");
        if(ans[edge[i].second]==1) print("Aoki");
    }
}
//Shiritori