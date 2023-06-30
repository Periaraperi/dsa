#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) {
        int n,k,x; cin >> n >> k >> x;
        if (x!=1) {
            cout << "YES\n" << n << '\n';
            for (int i=0; i<n; ++i)
                cout << 1 << " ";
            cout << '\n';
            continue;
        }
        if (k>=2) {
            if (n%2==0) {
                cout << "YES\n";
                cout << n/2 << '\n';
                for (int i=0; i<n/2; ++i)
                    cout << "2 ";
                cout << '\n';
            } else {
                if (k==2) {
                    cout << "NO\n";
                    continue;
                }
                cout << "YES\n";
                cout << 1 + (n-3)/2 << '\n';
                cout << 3 << " ";
                for (int i=0; i<(n-3)/2; ++i)
                    cout << "2 ";
                cout << '\n';
            }
        } else {
            cout << "NO\n";
        }

    }
    return 0;
}

