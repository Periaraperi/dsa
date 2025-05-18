#include <bits/stdc++.h>
 
using namespace std;
 
bool check(vector<string>& v, int n, int m)
{
    for (int i=0; i<n-1; ++i) {
        int cnt = 0;
        for (int j=0; j<m; ++j) {
            if (v[i][j]!=v[i+1][j]) {
                ++cnt;
            }
        }
        if (cnt>1) return false;
    }
    return true;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while(t--) {
        int n,m; cin >> n >> m;
        vector<string> v(n);
        for (int i=0; i<n; ++i) {
             cin >> v[i];
        }
        sort(v.begin(),v.end());

        if (check(v,n,m)) {
            cout << "Yes\n";
            return 0;
        }

        bool ok = false;
        do {
            if (check(v,n,m)) {
                ok = true;
                break;
            }
        }
        while (next_permutation(v.begin(),v.end()));
        if (ok) cout << "Yes\n";
        else    cout << "No\n";
    }
    return 0;
}

