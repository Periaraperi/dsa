#include <algorithm>
#include <iostream>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; cin >> t;

    while (t--) {
        int n; cin >> n;
        vector<int64_t> v(n);
        int count_neg {};
        for (auto& i:v) {
            cin >> i;
            if (i < 0) ++count_neg;
        }
        int count_pos {n-count_neg};

        sort(v.begin(), v.end(), [](int64_t a, int64_t b) { return abs(a) < abs(b); });

        if (abs(v.front()) == abs(v.back())) {
            if (abs(count_pos-count_neg) <= 1 || count_pos == 0 || count_neg == 0) {
                cout << "Yes\n";
                continue;
            }
        }

        bool ok {true};
        for (int i=1; i<n-1; ++i) {
            if (v[i]*v[i] != v[i-1]*v[i+1]) {
                ok = false;
                break;
            }
        }
        if (ok) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}

