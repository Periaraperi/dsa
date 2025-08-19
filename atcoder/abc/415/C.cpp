#include <iostream>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t{1}; cin >> t;
    while (t--) {
        int n; string s;
        cin >> n >> s;
        s = "0"+s;
        vector<bool> dp(1<<n, false);
        dp[0] = true;
        for (int state{}; state<(1<<n); ++state) {
            if (!dp[state]) continue;
            for (int i{}; i<n; ++i) {
                if ((state & (1<<i)) == 0) {
                    // add i-th bit to this state
                    int next_state {state | (1<<i)};
                    if (s[next_state] != '1') {
                        dp[next_state] = true;
                    }
                }
            }
        }
        if (dp[(1<<n)-1]) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
