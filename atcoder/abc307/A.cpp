#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i=0; i<n; ++i) {
            int64_t ans = 0;
            for (int j=0; j<7; ++j) {
                int64_t x; cin >> x;
                ans += x;
            }
            cout << ans << ' ';
        }
        cout << '\n';
    }
    return 0;
}

