#include <bits/stdc++.h>
 
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; ++i) cin >> a[i];
        if (n==1) {
            cout << 1 << '\n';
            continue;
        }

        int k = 0;
        for (int i=0; i<n; ++i) {
            if (a[i]==n) {
                k = i;
                break;
            }
        }

        if (k==0) {
            for (int i=0; i<n; ++i) {
                if (a[i]==n-1) {
                    k = i;
                    break;
                }
            }
        }

        vector<int> best;
        best.push_back(a[k-1]);
        for (int i=0; i<k-1; ++i) best.push_back(a[i]);
        int i = 0;
        while ((k-1)-i>=0) {
            vector<int> v;
            for (int j=k-1; j>=(k-1)-i; --j) {
                v.push_back(a[j]);
            }
            for (int j=0; j<(k-1)-i; ++j) {
                v.push_back(a[j]);
            }
            best = max(best,v);
            ++i;
        }
        vector<int> ans;
        for (int j=k; j<n; ++j) {
            ans.push_back(a[j]);
        }
        for (auto& j:best) ans.push_back(j);
        
        vector<int> v;
        v.push_back(a[n-1]);
        for (i=0; i<n-1; ++i) v.push_back(a[i]);
        ans = max(ans,v);

        for (auto& j:ans) cout << j << ' ';
        cout << '\n';
    }
    return 0;
}

