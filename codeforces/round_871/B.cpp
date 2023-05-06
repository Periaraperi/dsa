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
         for (int i=0; i<n; ++i) cin >> v[i];
         int ans = 0;
         for (int i=0; i<n; ++i) {
            if (v[i]==0) {
                int cnt = 0;
                while (i<n && v[i]==0) {
                    ++i;
                    ++cnt;
                }
                --i;
                ans = max(ans,cnt);
            }
         }
         cout << ans << '\n';
    }
    return 0;
}

