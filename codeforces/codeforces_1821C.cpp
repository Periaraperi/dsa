#include <bits/stdc++.h>
 
using namespace std;
 
// main idea, fixing characters
// solving from backwards

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; cin >> t;
    while(t--) {
        string s; cin >> s;
        int ans = s.size();
        vector<int> freq(26);
        for (auto& ch:s) ++freq[ch-'a'];

        for (char i='a'; i<='z'; ++i) {
            if (freq[i-'a']==0) continue;
            int max_block = 0;
            for (int j=0; j<s.size(); ++j) {
                if (s[j]!=i) {
                    int st = j;
                    while (j<s.size() && s[j]!=i) {
                        ++j;
                    }
                    --j;
                    max_block = max(max_block,j-st+1);
                }
            }
            int cnt = 0;
            while (max_block>0) {
                ++cnt;
                max_block /= 2;
            }
            ans = min(ans,cnt);
        }
        cout << ans << '\n';
    }
    return 0;
}

