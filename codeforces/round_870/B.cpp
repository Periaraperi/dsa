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
        for (int i=0; i<n; ++i) {
            cin >> v[i];
        }
        int x = 0;
        for (int i=0; i<n; ++i) {
            x = __gcd(x,abs(v[i]-v[n-i-1]));
        }
        cout << x << '\n';
    }
    return 0;
}

