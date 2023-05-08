#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        int n,m; cin >> n >> m;
        vector<int> v(n*m);
        for (auto& i:v) cin >> i;
        
        sort(v.begin(),v.end());

        int64_t smallest = v[0];
        int64_t large_down, large_right;
        if (n>m) {
            large_down = v[n*m-1];
            large_right = v[n*m-2];
        } else {
            large_right = v[n*m-1];
            large_down = v[n*m-2];
        }
        int64_t ans1 = 0;
        for (int i=1; i<n; ++i) {
            ans1 += (large_down-smallest);
        }
        for (int i=1; i<m; ++i) {
            ans1 += (large_right-smallest);
        }
        for (int i=1; i<n; ++i) {
            for (int j=1; j<m; ++j) {
                ans1 += (v[n*m-1]-v[0]);
            }
        }

        int64_t largest = v[n*m-1];
        int64_t smallest_down, smallest_right;
        if (n>m) {
            smallest_down = v[0];
            smallest_right = v[1];
        } else {
            smallest_down = v[1];
            smallest_right = v[0];
        }

        int64_t ans2 = 0;
        for (int i=1; i<n; ++i) {
            ans2 += (largest-smallest_down);
        }
        for (int i=1; i<m; ++i) {
            ans2 += (largest-smallest_right);
        }
        for (int i=1; i<n; ++i) {
            for (int j=1; j<m; ++j) {
                ans2 += (v[n*m-1]-v[0]);
            }
        }
        cout << max(ans1,ans2) << '\n';

    }
    return 0;
}

