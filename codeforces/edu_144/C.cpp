#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    constexpr long long MOD = 998244353;
    while(t--) {
        int l,r; cin >> l >> r;
        int len = 0; // optimal length of set
        for (int num=l; num<=r; num*=2) {
            ++len;
        }
        int x = r/pow(2,len-1); // largest starting element in set with optimal length
        int y = r/(3*pow(2,len-2)); // largest starting element such that multiplying by 3 works
        long long ans = x-l+1;
        if (y>=l)
            ans = (ans+(y-l+1)*(len-1))%MOD;
        cout << len << " " << ans << '\n';
    }
    return 0;
}

