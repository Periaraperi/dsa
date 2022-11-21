#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v(n);
        for (auto& i:v) cin >> i;
        int l = 0;
        bool ok = false;
        bool valley = false;
        // 3 2 2 1 2 2 3
        while (l<n) {
            int r = l;
            while (r+1<n && v[l]==v[r+1]) {
                ++r;
            }
            bool left_ok = (l==0 || v[l]<v[l-1]);
            bool right_ok = (r==n-1 || v[r]<v[r+1]);
            if (left_ok && right_ok) {
                if (valley) {
                    ok = false;
                    break;
                } else {
                    valley = true;
                    ok = true;
                }
            } 
            l = r+1;
        }
        (ok) ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}

