#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) {
        uint64_t ans = 0;
        for (uint64_t i=0; i<64; ++i) {
            uint64_t x; cin >> x;
            ans += ((1ULL<<i)*x);
        }
        cout << ans << '\n';
    }
    return 0;
}

