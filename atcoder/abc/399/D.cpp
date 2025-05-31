#include <algorithm>
#include <iostream>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(2*n);
        vector<vector<int>> p(n+1);
        for (int i{}; i<2*n; ++i) {
            cin >> v[i];
            p[v[i]].push_back(i);
        }

        vector<bool> switched(n+1, false);
        int ans{};
        for (int i{}; i<2*n-1; ++i) {
            int a{v[i]}, b{v[i+1]};
            if (p[a][0]+1 == p[a][1] || p[b][0]+1 == p[b][1]) continue;
            vector<int> c {p[a][0], p[a][1], p[b][0], p[b][1]};
            sort(c.begin(), c.end());
            if (c[0]+1 == c[1] && c[2]+1 == c[3]) {
                if (!switched[a] || !switched[b]) {
                    ++ans;
                    switched[a] = switched[b] = true;
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}

