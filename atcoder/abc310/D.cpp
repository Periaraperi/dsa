#include <bits/stdc++.h>
 
using namespace std;

// brute force, very unintuitive for me
// Jiangly's code helped a lot to understand
// Moral: need to practice brute force search I guess ...
// had several eureka/ahhaa moments

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,t,m; cin >> n >> t >> m;
    vector<array<int,2>> bad(m);
    for (int i=0; i<m; ++i) {
        cin >> bad[i][0] >> bad[i][1];
        --bad[i][0]; --bad[i][1];
    }
    
    vector<int> teams(t);
    int64_t ans = 0;
    auto dfs = [&ans,&bad,&teams,n,t](auto dfs, int player, int team) -> void {
        if (player==n) {
            if (team!=t) return;
            bool ok = true;
            for (int i=0; i<bad.size(); ++i) {
                if (teams[bad[i][0]]==teams[bad[i][1]]) {
                    ok = false;
                    break;
                }
            }
            ans += ok;
            return;
        }
        for (int i=0; i<=team; ++i) {
            teams[player] = i;
            dfs(dfs,player+1,max(i+1,team));
        }
    };
    dfs(dfs,0,0);
    cout << ans << '\n';
    return 0;
}
