#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n);
        vector<int> a;
        vector<int> freq(101,0);
        for (int i=0; i<n; ++i) {
            cin >> v[i];
            if (freq[v[i]]==0) {
                a.push_back(v[i]);
            }
            ++freq[v[i]];
        }
        
        bool ok = true;
        sort(a.begin(),a.end());
        for (int i=0; i<a.size(); ++i) {
            if (a[i]!=i) {
                ok = false;
                break;
            }
        }
        for (int i=1; i<a.size(); ++i) {
            if (freq[a[i]]>freq[a[i-1]]) {
                ok = false;
                break;
            }
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";

    }
    return 0;
}

