#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        int n; cin >> n;
        int odds = 0;
        int evens = 0;
        for (int i=0; i<n; ++i) {
            int a; cin >> a;
            if (a%2==0) evens += a;
            else        odds += a;
        }
        if (evens>odds) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

