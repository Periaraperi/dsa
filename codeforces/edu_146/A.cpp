#include <bits/stdc++.h>
 
using namespace std;
 
long long gcd(long long a, long long b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        long long n,k; cin >> n >> k;
        if (n%gcd(2,k)==0) cout << "YES\n";
        else cout << "NO\n";
         
    }
    return 0;
}

