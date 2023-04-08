#include <bits/stdc++.h>
 
using namespace std;
 
// cute prefix sum problem
// given array consisting of 0's and 1's
// count number of subarrays containing k 1's
// or in other words, count number of subarrays
// with sum k

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin >> t;
    while(t--) {
        int k; cin >> k;
        string s; cin >> s;
        vector<int> pref(s.size()+1);
        for (int i=1; i<=(int)s.size(); ++i) {
            pref[i] += (pref[i-1] + (s[i-1]=='1' ? 1:0));
        }
        vector<int> cnt(s.size()+1);
        cnt[0] = 1;
        long long ans = 0;
        for (int i=1; i<=(int)s.size(); ++i) {
            if (pref[i]-k>=0)
                ans += cnt[pref[i]-k];
           ++cnt[pref[i]];
        }
        cout << ans << '\n';
    }
    return 0;
}

