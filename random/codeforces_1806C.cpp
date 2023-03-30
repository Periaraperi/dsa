#include <bits/stdc++.h>
 
using namespace std;

// constructive math problem
// handling of special edge cases
// simple proofs
// system of equations got us vital information

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        int n; cin >> n;
        long long ans = 0;
        vector<long long> v(2*n);
        for (auto& i:v) {
            cin >> i;
            ans += abs(i); // assume that q is all zeros
        }
        
        if (n==1) {
            cout << min(ans,abs(v[0]-v[1])) << '\n';
            continue;
        } else if (n==2) { // special even case
            // check [2,2,2,2] and general case later
            long long tmp = 0;
            for (auto i:v) tmp += abs(i-2);
            ans = min(ans,tmp);
        }

        if (n%2==0) { // general case when n is even
            // q consists of 1 n and 2n-1 -1s
            long long sm = 0;
            for (auto i:v) sm += abs(i+1); // assume all elems in q are -1
            // find best position for n in array q
            for (auto i:v) ans = min(ans,sm-abs(i+1)+abs(i-n));
        }
        cout << ans << '\n';
    }
    return 0;
}

