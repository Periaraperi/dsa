#include <bits/stdc++.h>
 
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while(t--) {
        int n,q; cin >> n >> q;
        vector<set<int>> g(n+1);

        int ans = n;
        while (q--) {
            int x; cin >> x;
            if (x==1) {
                int a,b; cin >> a >> b;
                if (g[a].empty()) --ans;
                if (g[b].empty()) --ans;
                g[a].insert(b);
                g[b].insert(a);
            } else {
                int a; cin >> a;
                for (auto i:g[a]) {
                    if (g[i].size()==1) ++ans;
                    g[i].erase(a);
                }
                if (!g[a].empty()) {
                    ++ans;
                    g[a].clear();
                }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}

