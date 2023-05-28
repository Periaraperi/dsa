#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; ++i) {
            cin >> a[i];
        }
        for (auto i:a) cout << n-i+1 << " ";
        cout << '\n';
    }
    return 0;
}

