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

string S;
int K;
int nex[100009][26];

int main() {
    cin >> S >> K;
    int n = sz(S);

    rep(i,26) nex[n][i] = n;
    rrep(i,n) rep(j,26) {
            if ((int)(S[i] - 'a') == j) {
                nex[i][j] = i;
            } else {
                nex[i][j] = nex[i + 1][j];
            }
    }

    string Answer = "";
    int CurrentPos = 0;
    rep1(i,K) rep(j,26) {
            int NexPos = nex[CurrentPos][j];
            int MaxPossibleLength = (n - NexPos - 1) + i;
            if (MaxPossibleLength >= K) {
                Answer += (char)('a' + j);
                CurrentPos = NexPos + 1;
                break;
            }
    }

    cout << Answer << endl;
    return 0;
}

//Educational 90: No.6