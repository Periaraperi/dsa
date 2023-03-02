#include <bits/stdc++.h>
    
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt = 1; cin >> tt;
    while (tt--) {
        int n,k; cin >> n >> k;
        string s; cin >> s;
        vector<int> freq(130,0);
        for (auto ch:s) {
            ++freq[ch];
        }

        int ans = 0;
        for (char ch='A'; ch<='Z'; ++ch) {
            char ch2 = std::tolower(ch);
            int mn = min(freq[ch],freq[ch2]);
            ans += mn;
            freq[ch] -= mn;
            freq[ch2] -= mn;
        }

        for (char ch='A'; ch<='Z'; ++ch) {
            char ch2 = std::tolower(ch);
            if (k<=0) break;
            int mx = max(freq[ch],freq[ch2]);
            mx /= 2;
            ans += min(k,mx);
            k -= mx;
        }
        cout << ans << '\n';
    }
    
    return 0;
}