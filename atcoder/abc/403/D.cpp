#include <algorithm>
#include <iostream>
#include <vector>
 
using namespace std;

void dfs(int v, const vector<vector<int>>& g, vector<bool>& vis, vector<int>& component)
{
    if (vis[v]) return;
    component.push_back(v);
    vis[v] = true;
    for (const auto& u:g[v]) {
        dfs(u, g, vis, component);
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d; cin >> n >> d;
    vector<int> v(n);
    for (auto& i:v) cin >> i;

    int maxn {*max_element(v.begin(), v.end())};
    vector<int> freq(maxn+1, 0);

    for (const auto& i:v) ++freq[i];

    int ans {};
    if (d == 0) {
        for (int num{}; num<=maxn; ++num) {
            if (freq[num] > 0) {
                ans += (freq[num]-1);
            }
        }
    }
    else {
        vector<vector<int>> g(maxn+1);
        for (int i{}; i<=maxn; ++i) {
            if (freq[i] > 0) {
                if (i+d <= maxn && i-d >= 0 && freq[i+d] == 0 && freq[i-d] == 0) {
                    freq[i] = 0; // we don't care about these numbers. They can't pair up with anyone
                    continue;
                }
                if (i+d <= maxn && freq[i+d] > 0) {
                    g[i].push_back(i+d);
                    g[i+d].push_back(i);
                }
            }
        }
        vector<bool> vis(maxn+1, false);
        vector<vector<int>> components;
        for (int i{}; i<=maxn; ++i) {
            if (!vis[i] && freq[i] > 0) {
                components.push_back({});
                dfs(i, g, vis, components.back());
            }
        }

        for (const auto& component:components) {
            int removed {freq[component[0]]}; // store minimum number of removals, such that prefix is "good" and last element in that prefix is removed
            int kept {0};                     // store minimum number of removals, such that prefix is "good" and last element in that prefix is kept
            for (int i{1}; i<(int)component.size(); ++i) {
                int new_removed = min(kept, removed) + freq[component[i]];
                int new_kept = removed;

                removed = new_removed;
                kept = new_kept;
            }
            ans += min(kept, removed);
        }
    }
    cout << ans << '\n';
    return 0;
}

