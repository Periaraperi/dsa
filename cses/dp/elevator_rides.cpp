#include <bits/stdc++.h>
 
using namespace std;
 
// bitmask dp

struct state {
    int rides;
    int64_t sum;
    friend bool operator<(const state& lhs, const state& rhs) 
    {
        if (lhs.rides==rhs.rides)
            return lhs.sum<rhs.sum;
        return lhs.rides<rhs.rides;
    }
};

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    int64_t x; cin >> x;
    vector<int64_t> w(n);
    for (auto&& weight:w) 
        cin >> weight;
    
    constexpr int INF = 1e9;
    vector<state> dp(1<<n);
    for (auto& s:dp) {
        s = {INF,INF};
    }
    dp[0] = {1,0};

    for (int mask=1; mask<(1<<n); ++mask) { // mask represents subset of w
        for (int i=0; i<(int)w.size(); ++i) {
            // we want to get prev subset
            // so if w[i] is not in current mask ignore 
            // (we can still proccess it, since the answers will be infinity for larger subsets at this point)
            auto mk = mask^(1<<(n-i-1)); // possibly subset with length 1 less or 1 more
            if (mask & (1<<(n-i-1))) { // check that it is 1 less, we only care about lesser case
                if (dp[mk].sum+w[i]<=x) {
                    dp[mask] = min(dp[mask],{dp[mk].rides,dp[mk].sum+w[i]});
                } else {
                    dp[mask] = min(dp[mask],{dp[mk].rides+1,min(dp[mk].sum,w[i])});
                }
            }
        }
    }
    cout << dp[(1<<n)-1].rides << '\n';
    return 0;
}

