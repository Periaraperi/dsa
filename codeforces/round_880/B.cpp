#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while (t--) {
        int64_t n,k,g; cin >> n >> k >> g;
        if (n==1) {
            cout << 0 << '\n';
            continue;
        }

        int G;
        if (g%2==0) G = g/2;
        else G = g/2 + 1;
        int64_t x;
        if (g%2==0) x = g/2 - 1;
        else x = g/2;
        if (x==0) {
            cout << 0 << '\n';
            continue;
        }
        
        int64_t y = min(n-1,(k*g)/x);
        int64_t rem = k*g-y*x;

        int64_t pays = 0;
        if ((rem%g)>=G) {
            pays += (rem+(g-(rem%g)));
        } else {
            pays += (rem-(rem%g));
        }
        cout << k*g-pays << '\n';
    }
    return 0;
}

