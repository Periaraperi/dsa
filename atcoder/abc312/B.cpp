#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m; cin >> n >> m;
    vector<string> v(n);
    for (auto& i:v) cin >> i;

    auto check = [&v,n,m](int i, int j) -> bool {
        if (i+8>=n || j+8>=m) return false;
        for (int k=0; k<3; ++k) {
            auto s = v[i+k].substr(j,4);
            if (s!="###.") return false;
        }
        if (v[i+3].substr(j,4)!="....") return false;

        for (int k=0; k<3; ++k) {
            auto s = v[i+8-k].substr(j+5,4);
            if (s!=".###") return false;
        }
        if (v[i+8-3].substr(j+5,4)!="....") return false;
        return true;
    };

    vector<pair<int, int>> ans;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            if (check(i,j)) {
                ans.push_back({i,j});
            }
        }
    }
    sort(ans.begin(),ans.end());
    for (auto& [i,j]:ans) cout << i+1 << " " << j+1 << '\n';

    return 0;
}

