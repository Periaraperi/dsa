#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; //cin >> t;
    while (t--) {
        int k; cin >> k;
        for (int i=65; i<65+k; ++i) {
            cout << (char)i;
        }
        cout << '\n';
    }
    return 0;
}