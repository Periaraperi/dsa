#include <iostream>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        int l{-1};
        for (int i{}; i<n-1; ++i) {
            if (s[i] > s[i+1]) {
                l = i;
                break;
            }
        }

        if (l == -1) {
            cout << s << '\n';
            continue;
        }

        int r {n-1};
        for (int i{l+1}; i<n; ++i) {
            if (s[l] < s[i]) {
                r = i-1;
                break;
            }
        }
        for (int i{}; i<l; ++i) cout << s[i];
        for (int i{l+1}; i<=r; ++i) cout << s[i];
        cout << s[l];
        for (int i{r+1}; i<n; ++i) cout << s[i];
        cout << '\n';
    }
    return 0;
}

