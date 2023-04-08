#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1; cin >> t;
    while (t--) {
        long long n,m; cin >> n >> m;
        auto nn = n;
        int c2 = 0;
        int c5 = 0;
        while (nn>0 && nn%2==0) {
            nn /= 2;
            ++c2;
        }
        while (nn>0 && nn%5==0) {
            nn /= 5;
            ++c5;
        }
        long long k = 1;
        while (c2<c5 && 2*k<=m) {
            ++c2;
            k *= 2;
        }
        while (c5<c2 && 5*k<=m) {
            ++c5;
            k *= 5;
        }
        while (c5==c2 && 10*k<=m) {
            ++c5;
            ++c2;
            k *= 10;
        }
        cout << n*k*(m/k) << '\n';
        
    }

    return 0;
}