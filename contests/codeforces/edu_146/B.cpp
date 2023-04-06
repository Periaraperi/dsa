#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        long long a,b; cin >> a >> b;
        long long ans = a+b;
        for (long long i=0; i*i<=a+b+1; ++i) {
            auto x = (long long)ceil((double)a/(i+1))+(long long)ceil((double)b/(i+1))+i;
            ans = min(ans,x);
        }
        cout << ans << '\n';
    }
    return 0;
}

