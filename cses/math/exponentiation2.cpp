#include <bits/stdc++.h>
 
using namespace std;

long long binary_exp(long long a, long long b, long long mod)
{
    if (b==0) return 1;
    long long res = binary_exp(a,b/2,mod);
    res = (res*res)%mod;
    if (b%2==1) res = (res*a)%mod;
    return res;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    constexpr long long MOD = 1e9 + 7;

    int t = 1; cin >> t;
    while(t--) {
        int a,b,c; cin >> a >> b >> c;
        long long x = binary_exp(b,c,MOD-1);
        cout << binary_exp(a,x,MOD) << '\n';
    }
    return 0;
}

