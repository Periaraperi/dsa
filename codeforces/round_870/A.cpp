#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v(n);
        for (auto& i:v) {
            cin >> i;
        }
        int ans = -1;
        for (int i=0; i<=n; ++i) {
            int cnt = 0;
            for (int j=0; j<n; ++j) {
                if (v[j]>i) {
                    ++cnt;
                }
            }
            if (cnt==i) {
                ans = cnt;
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

