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
        vector<int> suf_max(n,-1);
        vector<int> pref_max(n,-1);
        for (int i=0; i<n; ++i) {
            cin >> v[i];
        }

        pref_max[0] = v[0];
        for (int i=1; i<n; ++i) {
            pref_max[i] = max(pref_max[i-1],v[i]); 
        }
        suf_max[n-1] = v[n-1];
        for (int i=n-2; i>=0; --i) {
            suf_max[i] = max(suf_max[i+1],v[i]);
        }

        for (int i=0; i<n; ++i) {
            if (i==0) {
                cout << v[i]-suf_max[i+1] << " ";
            } else if (i==n-1) {
                cout << v[i]-pref_max[i-1] << " ";
            } else {
                cout << v[i]-max(suf_max[i+1],pref_max[i-1]) << " ";
            }
        }
        cout << '\n';

    }
    return 0;
}

