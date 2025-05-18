#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while(t--) {
        int64_t n,m; cin >> n >> m;
        if (n%m==0) cout << n/m << '\n';
        else cout << n/m + 1 << '\n';
    }
    return 0;
}

