#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (auto& i:a) cin >> i;
        for (auto& i:b) cin >> i;

        vector<int> cnt_a(2*n+1), cnt_b(2*n+1);
        for (int i=0; i<n; ++i) {
            int cnt = 1;
            int x = a[i];
            while (i+1<n && a[i]==a[i+1]) {
                ++cnt;
                ++i;
            }
            cnt_a[x] = max(cnt_a[x],cnt);
        }
        for (int i=0; i<n; ++i) {
            int cnt = 1;
            int x = b[i];
            while (i+1<n && b[i]==b[i+1]) {
                ++cnt;
                ++i;
            }
            cnt_b[x] = max(cnt_b[x],cnt);
        }
        auto ans = 0;
        for (int i=1; i<=2*n; ++i) {
            ans = max(ans,cnt_a[i]+cnt_b[i]);
        }
        cout << ans << '\n';
    }
    return 0;
}

