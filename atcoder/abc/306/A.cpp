#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        for (auto ch:s) {
            cout << ch << ch;
        }
        cout << '\n';

    }
    return 0;
}

