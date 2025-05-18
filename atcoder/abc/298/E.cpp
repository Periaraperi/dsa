#include <bits/stdc++.h>
 
using namespace std;
 
/*
    upsolving E, problem on probability, mod inverse, dp
    interesting ovservations.
*/

constexpr int64_t MOD = 998244353;

int64_t bin_pow(int64_t a, int64_t b)
{
    int64_t res = 1;
    while (b>0) {
        if (b%2==1) res = (res*a)%MOD;
        a = (a*a)%MOD;
        b /= 2;
    }
    return res;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,A,B,P,Q; cin >> N >> A >> B >> P >> Q;
    
    vector<vector<vector<int64_t>>> dp(N+1,vector<vector<int64_t>>(N+1,vector<int64_t>(2)));
    int aoki_turn = 0, takahashi_turn = 1;
    dp[B][A][takahashi_turn] = 1;
    
    // dp[i][j][{A,T}] = probability that Aoki is on point i and Takahashi is on point j when next move is A or T
    // ans = SUM dp[i][N][aoki_turn] where 1<=i<=N-1
    for (int i=1; i<N; ++i) {
        for (int j=1; j<N; ++j) {
            auto prob = bin_pow(P,MOD-2);
            for (int k=1; k<=P; ++k) {
                dp[i][min(j+k,N)][aoki_turn] += ((prob*dp[i][j][takahashi_turn])%MOD);
                dp[i][min(j+k,N)][aoki_turn] %= MOD;
            }
            prob = bin_pow(Q,MOD-2);
            for (int k=1; k<=Q; ++k) {
                dp[min(i+k,N)][j][takahashi_turn] += ((prob*dp[i][j][aoki_turn])%MOD);
                dp[min(i+k,N)][j][takahashi_turn] %= MOD;
            }
        }
    }
    auto res = 0LL;
    for (int i=1; i<=N-1; ++i) {
        res += dp[i][N][aoki_turn];
        res %= MOD;
    }
    cout << res << '\n';

    return 0;
}

