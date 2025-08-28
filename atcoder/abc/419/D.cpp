#include <iostream>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    struct range {
        int l{};
        int r{};
    };
    vector<int> pref(n+2, 0);
    vector<range> ranges(m);
    for (auto& [l, r]:ranges) {
        cin >> l >> r;
        ++pref[l];
        --pref[r+1];
    }
    for (int i{1}; i<=n; ++i) {
        pref[i] += pref[i-1];
    }
    string ans; ans.reserve(n);
    for (int i{1}; i<=n; ++i) {
        if (pref[i]%2 == 0) {
            ans.push_back(s[i-1]);
        }
        else {
            ans.push_back(t[i-1]);
        }
    }
    cout << ans << '\n';
    return 0;
}

