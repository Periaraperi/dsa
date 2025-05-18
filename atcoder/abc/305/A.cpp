#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n%5==0) cout << n << '\n';
        else {
            int x = (n/5) * 5;
            int y = x + 5;
            if (n-x<y-n) cout << x << '\n';
            else cout << y << '\n';
        }
    }
    return 0;
}

