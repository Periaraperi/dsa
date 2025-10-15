#include <iostream>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t{1}; cin >> t;
    while (t--) {
        int n, m, k; cin >> n >> m >> k;
        string s; cin >> s;
        vector<vector<int>> graph(n);
        for (int i{}; i<m; ++i) {
            int a, b; cin >> a >> b;
            --a; --b;
            graph[a].emplace_back(b);
        }

        vector dp(n, vector<int>(2*k+1, false));
        for (int i{}; i<n; ++i) {
            if (s[i]=='A') dp[i][2*k] = true;
        }

        for (int i{2*k-1}; i>=0; --i) {
            for (int j{}; j<n; ++j) {
                if (i%2) dp[j][i] = true;
                else     dp[j][i] = false;
                for (const auto& v:graph[j]) {
                    if (dp[v][i+1] != dp[j][i]) {
                        dp[j][i] = dp[v][i+1];
                        break;
                    }
                }
            }
        }
        
        if (dp[0][0]) cout << "Alice\n";
        else          cout << "Bob\n";
        
    }
    return 0;
}

