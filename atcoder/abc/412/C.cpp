#include <algorithm>
#include <iostream>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n);
        for (auto& i:v) cin >> i;

        int a {v.front()};
        int b {v.back()};

        if (b <= 2*a) {
            cout << 2 << '\n';
            continue;
        }
        
        vector<int> mids;
        for (int i{1}; i<n-1; ++i) {
            mids.emplace_back(v[i]);
        }
        sort(mids.begin(), mids.end());

        int i {};
        int m {(int)mids.size()};
        int add {};
        while (i<m) {
            int next {};
            bool changed {};
            while (i < m && mids[i] <= 2*a) {
                next = mids[i];
                ++i;
                changed = true;
            }
            if (!changed) break;
            a = next;
            ++add;
            if (b <= 2*a) break;
        }
        
        if (b > 2*a) {
            cout << -1 << '\n';
        }
        else {
            cout << add+2 << '\n';
        }

    }
    return 0;
}

