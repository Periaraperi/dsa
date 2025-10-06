#include <iostream>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    vector<int64_t> v(n);
    for (auto& i:v) cin >> i;

    vector<int64_t> pref(n);
    pref[0] = v.front();
    for (int i{1}; i<n; ++i) {
        pref[i] = pref[i-1] + v[i];
    }

    int offset {};

    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int c; cin >> c;
            offset += c;
            offset %= n;
        }
        else {
            int l, r; cin >> l >> r;
            --l; --r;
            l = (l+offset)%n;
            r = (r+offset)%n;
            if (l > r) {
                int64_t a {}; 
                if (l!=0) a = pref[l-1];
                cout << (pref[n-1]-a) + pref[r] << '\n';
            }
            else {
                int64_t a {}; 
                if (l!=0) a = pref[l-1];
                cout << pref[r]-a << '\n';
            }
        }
    }

    return 0;
}

