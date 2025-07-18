#include <iostream>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int64_t sm {((int64_t)n*(n+1)/2)};
    if (sm%2 == 0) {
        vector<bool> used(n+1, false);
        int64_t s {};
        int k {n};
        int sz {};
        while (s < sm/2) {
            if (s+k <= sm/2) {
                s += k;
                used[k] = true;
                ++sz;
            }
            --k;
        }
        cout << "YES\n";
        cout << sz << '\n';
        for (int i{1}; i<=n; ++i) {
            if (used[i]) {
                cout << i << " ";
            }
        }
        cout << '\n' << n-sz << '\n';
        for (int i{1}; i<=n; ++i) {
            if (!used[i]) {
                cout << i << " ";
            }
        }
        cout << '\n';
    }
    else {
        cout << "NO\n";
    }
    return 0;
}

