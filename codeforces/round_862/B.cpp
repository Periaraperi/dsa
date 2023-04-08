#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        vector<int> freq(26);
        for (auto ch:s) ++freq[ch-'a'];
        char beg_ch = ' ';
        for (int i='a'; i<='z'; ++i) {
            if (freq[i-'a']!=0) {
                beg_ch = i;
                break;
            }
        }
        int last = 0;
        for (int i=n-1; i>=0; --i) {
            if (beg_ch==s[i]) {
                last = i;
                break;
            }
        }

        string ans;
        ans.push_back(beg_ch);
        for (int i=0; i<n; ++i) {
            if (s[i]==beg_ch && i==last) { 
                continue;
            }
            ans.push_back(s[i]);
        }
        cout << ans << '\n';
    }
    return 0;
}

