#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while(t--) {
        int n,a,b; cin >> n >> a >> b;
        int ans = -1;
        for (int i=0; i<n; ++i) {
            int c; cin >> c;
            if (a+b==c) {
                ans = i+1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

