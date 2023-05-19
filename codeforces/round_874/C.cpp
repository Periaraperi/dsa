#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        int n; cin >> n;
        
        constexpr int INF = 1e9+100;
        int smallest_odd = INF;
        int smallest_even = INF;
        vector<int> a(n);
        for (int i=0; i<n; ++i) {
            cin >> a[i];
            if (a[i]%2==0) smallest_even = min(smallest_even,a[i]);
            else smallest_odd = min(smallest_odd,a[i]);
        }

        if (smallest_odd==INF || smallest_even==INF) {
            cout << "YES\n";
        } else {
            // make all odd
            bool all_odd = true;
            for (int i=0; i<n; ++i) {
                if (a[i]%2==0) {
                    a[i] -= smallest_odd;
                    if (a[i]<=0) {
                        all_odd = false;
                        break;
                    }
                }
            }
            if (all_odd) {
                cout << "YES\n";
                continue;
            }

            bool all_even = true;
            for (int i=0; i<n; ++i) {
                if (a[i]%2==1) {
                    a[i] -= smallest_odd;
                    if (a[i]<=0) {
                        all_even = false;
                        break;
                    }
                }
            }
            if (all_even) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }

    }
    return 0;
}

