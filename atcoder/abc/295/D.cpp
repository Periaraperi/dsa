#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while(t--) {
        string s; cin >> s;
        int n = (int)s.size();
        // masks[i] holds mask where each bit in mask tells parity of occurance of digits
        // in prefix i, so if masks[i] == masks[j] where i<j ---> it is a good pair, otherwise not
        vector<int> cnt(1<<10);
        cnt[0] = 1;
        int mask = 0;
        long long ans = 0;
        for (int i=1; i<=n; ++i) { // finding pairs (i,j) such that masks[i]==masks[j], i<j 
            int d = s[i-1]-'0';
            mask ^= (1<<d);
            ans += cnt[mask];
            ++cnt[mask];
        }
        cout << ans << '\n';
    }
    return 0;
}

