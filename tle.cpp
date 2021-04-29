#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

long long N;
long long D[5009], C[5009], S[5009];

long long dp[5009][5009];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> D[i] >> C[i] >> S[i];
    }

    vector<tuple<long long, long long, long long>> tup;
    for (int i = 1; i <= N; i++) {
        tup.push_back(make_tuple(D[i], C[i], S[i]));
    }
    sort(tup.begin(), tup.end());
    for (int i = 1; i <= N; i++) {
        D[i] = get<0>(tup[i - 1]);
        C[i] = get<1>(tup[i - 1]);
        S[i] = get<2>(tup[i - 1]);
    }
    for(int i=1;i<N+1;i++) cout<<D[i]<<endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= 5000; j++) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if (j + C[i + 1] <= D[i + 1]) {
                dp[i + 1][j + C[i + 1]] = max(dp[i + 1][j + C[i + 1]], dp[i][j] + S[i + 1]);
            }
        }
    }

    long long Answer = 0;
    for (int i = 0; i <= 5000; i++) Answer = max(Answer, dp[N][i]);
    cout << Answer << endl;
    return 0;
}