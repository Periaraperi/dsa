#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int64_t> v(n);
        int64_t sm = 0;
        for (int i=0; i<n; ++i) {
            cin >> v[i];
            if (i%2==1) sm += (v[i]-v[i-1]);
        }
        if (n%2==1 || sm>=0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}

