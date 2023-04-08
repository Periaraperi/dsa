#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    int t = 1; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v(n);
        for (int i=0; i<n; ++i) cin >> v[i];
        vector<long long> pref(n+1);
        for (int i=1; i<=n; ++i) {
            pref[i] = pref[i-1]+v[i-1];
        }

        int lo = 1;
        int hi = n;
        while (lo<=hi) {
            int m = (lo+hi)/2;
            cout << "? " << m-lo+1 << " ";
            for (int i=lo; i<=m; ++i) {
                cout << i << " ";
            }
            cout << endl;
            long long weight; cin >> weight;
            if (weight<=pref[m]-pref[lo-1]) {
                lo = m+1;
            } else {
                hi = m-1;
            }
        }
        cout << "! " << lo << endl;

    }
    return 0;
}

