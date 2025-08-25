#include <algorithm>
#include <iostream>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    vector<int> v(n+1);
    vector<int64_t> pref_sum(n+1, 0);
    for (int i{1}; i<=n; ++i) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    int mx {*max_element(v.begin(), v.end())};

    for (int i{1}; i<=n; ++i) {
        pref_sum[i] = pref_sum[i-1] + v[i];
    }

    while (q--) {
        int64_t a; cin >> a;
        if (a > mx) cout << -1 << '\n';
        else {
            auto it {lower_bound(v.begin(), v.end(), a)};
            --it; // always exists, first elem is dummy 0
            int pref {(int)(it-v.begin())};
            int64_t x {pref_sum[pref]};
            int count_larger {n-pref};
            cout << x + (a-1)*count_larger + 1 << '\n';
        }
    }
    return 0;
}

