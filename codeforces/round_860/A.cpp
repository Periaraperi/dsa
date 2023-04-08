#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n), b(n); 
        for (auto& i:a) cin >> i;
        for (auto& i:b) cin >> i;
        int maxA = -1;
        int maxB = -1;
        for (int i=0; i<n; ++i) {
            if (a[i]>b[i]) swap(a[i],b[i]);

            maxA = max(maxA,a[i]);
            maxB = max(maxB,b[i]);
        }

        if (maxA==a[n-1] && maxB==b[n-1]) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

