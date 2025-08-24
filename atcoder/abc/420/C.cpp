#include <iostream>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    vector<int64_t> a(n), b(n);
    for (auto& i:a) cin >> i;
    for (auto& i:b) cin >> i;
    int64_t S{};
    for(int i{}; i<n; ++i) {
        S += min(a[i], b[i]);
    }
    while (q--) {
        char c; cin >> c;
        int x, y; cin >> x >> y;
        --x;
        if (c == 'A') {
            S += (min(b[x], (int64_t)y)-min(a[x], b[x]));
            a[x] = y;
        }
        else {
            S += (min(a[x], (int64_t)y)-min(a[x], b[x]));
            b[x] = y;
        }
        cout << S << '\n';
    }
    return 0;
}

