#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        int n,k; cin >> n >> k;
        vector<int> a(n), b(n);
        for (auto& i:a) cin >> i;
        for (auto& i:b) cin >> i;

        vector<pair<int,int>> aa(n);
        for (int i=0; i<n; ++i) {
            aa[i].first = a[i];
            aa[i].second = i;
        }
        sort(aa.begin(),aa.end());
        sort(b.begin(),b.end());
        
        vector<int> ans(n);
        for (int i=n-1; i>=0; --i) {
            ans[aa[i].second] = b[i];
        }
        for (auto& i:ans) cout << i << ' ';
        cout << '\n';
    }
    return 0;
}

