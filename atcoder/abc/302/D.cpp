#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while(t--) {
        int n,m; cin >> n >> m;
        int64_t d; cin >> d;
        vector<int64_t> a(n);
        vector<int64_t> b(m);
        for (auto& i:a) cin >> i;
        for (auto& i:b) cin >> i;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        int64_t ans = -1;
        for (int i=n-1; i>=0; --i) {
            auto it = upper_bound(b.begin(),b.end(),abs(a[i]));
            if (it!=b.begin()) {
                --it;
            }
            if (abs(a[i]-(*it))<=d) {
                ans = max(ans,a[i]+(*it));
            }
        }
        for (int i=m-1; i>=0; --i) {
            auto it = upper_bound(a.begin(),a.end(),abs(b[i]));
            if (it!=a.begin()) {
                --it;
            }
            if (abs(b[i]-(*it))<=d) {
                ans = max(ans,b[i]+(*it));
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

