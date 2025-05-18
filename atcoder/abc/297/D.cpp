#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while(t--) {
        long long a,b; cin >> a >> b;
        if (a==b) cout << 0 << '\n';
        else {
            long long cnt = 0;
            while (a!=b) {
                if (a>b) swap(a,b);
                if (a==1) {
                    cnt += (b-1);
                    b = a;
                } else {
                    if (b%a==0) {
                        cnt += (b/a-1);
                        b = a;
                    } else {
                        long long x = b/a;
                        cnt += x;
                        b -= x*a;
                    }
                }
            }
            cout << cnt << '\n';
        }
    }
    return 0;
}

