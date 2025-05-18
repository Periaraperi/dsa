#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v(n);
        for (auto& i:v) cin >> i;
        vector<bool> mp(n);
        for (int i=1; i<n; ++i) {
            if (abs(v[i]-v[i-1])!=1)
                mp[i-1] = true;
        }
        for (int i=0; i<n; ++i) {
            cout << v[i] << " ";
            if (mp[i]) {
                int x = v[i+1];
                if (x>v[i]) {
                    for (int j=v[i]+1; j<x; ++j) {
                        cout << j << " ";
                    }
                } else {
                    for (int j=v[i]-1; j>x; --j) {
                        cout << j << " ";
                    }
                }
            }
        }
        
    }
    return 0;
}

