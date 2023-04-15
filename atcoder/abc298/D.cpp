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
    int t = 1; //cin >> t;
    while(t--) {
        constexpr int64_t mod = 998244353;
        string s; s.reserve(200000);
        s.push_back('1');
        int sz = 1;
        int i = 0;
        int64_t num = 1;
        int q; cin >> q;
        while (q--) {
            int x; cin >> x;
            if (x==1) {
                int y; cin >> y;
                s.push_back(y+'0');
                num = (num*10 + y)%mod;
                ++sz;
            } else if (x==2) {
                --sz;
                if (s[i]==0) {
                    ++i;
                    continue;
                }
                auto k = ((s[i]-'0')*binary_exp(10,sz,mod))%mod;
                num -= k;
                num += mod;
                num %= mod;
                ++i;
            } else if (x==3) {
                cout << num%mod << '\n';
            }
        }
    }
    return 0;
}

