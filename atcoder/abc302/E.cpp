#include <bits/stdc++.h>
 
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while(t--) {
        int n,q; cin >> n >> q;
        set<int> in;
        set<int> not_in;
        vector<set<int>> g(n+1);
        for (int i=1; i<=n; ++i) not_in.insert(i);
        vector<int> cnt(n+1);

        while (q--) {
            int x; cin >> x;
            if (x==1) {
                int a,b; cin >> a >> b;
                g[a].insert(b);
                g[b].insert(a);
                ++cnt[a];
                ++cnt[b];
                not_in.erase(a);
                not_in.erase(b);
                in.insert(a);
                in.insert(b);
            } else {
                int a; cin >> a;
                for (auto i:g[a]) {
                    --cnt[i];
                    if (cnt[i]==0) {
                        not_in.insert(i);
                        in.erase(i);
                    }
                    g[i].erase(a);
                }
                cnt[a] = 0;
                g[a].clear();
                not_in.insert(a);
                in.erase(a);
            }
            cout << not_in.size() << '\n';
        }
    }
    return 0;
}

