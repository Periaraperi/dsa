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
        for (auto&& i:v) cin >> i;
        for (int i=0; i<n; ++i) {
            if (v[i]==1) ++v[i];
        }
        for (int i=1; i<n; ++i) {
            if (v[i]%v[i-1]==0) {
                ++v[i];
            }
        }
        for (auto i:v) cout << i << ' ';
        cout << '\n';
    }
    return 0;
}

