#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt = 1; //cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<string> v(n);

        vector<pair<int,int>> masks; // {mask_a, mask_b}
        // mask_a --> which letter is set in word (1 if set 0 if not)
        // mask_b --> parity of letter occurance in word (1 if odd times, 0 otherwise)

        for (auto& str:v) cin >> str;

        // number of 1s in mask
        auto count_set_bits = [](int mask) -> int {
            int res = 0;
            while (mask>0) {
                res += (mask%2);
                mask /= 2;
            }
            return res;
        };

        for (int i=0; i<n; ++i) {
            int present = 0;
            int parity = 0;
            for (const auto& ch:v[i]) {
                present |= (1<<(ch-'a'));
                parity ^= (1<<(ch-'a'));
            }
            if (count_set_bits(present)==26) continue;
            masks.push_back({present,parity});
        }

        // pair of strings is valid iff count_set_bits(mask_a_i | mask_a_j) ==
        //                           == count_set_bits(mask_b_i ^ mask_b_j) == 25

        // we fix k-th letter (don't include in answer) -->
        // mask_b_i ^ mask_b_j == reversed ignore

        long long ans = 0;
        for (int k=0; k<26; ++k) {
            map<int,int> mp;
            int ignore = (1<<k);
            for (auto p:masks) {
                int present = p.first;
                int parity = p.second;
                if (present&ignore) continue;
                int good_mask = ignore;
                for (int i=0; i<26; ++i) { // reverse ignore mask
                    good_mask ^= (1<<i);
                }
                int need = parity^good_mask;
                ans += mp[need];
                ++mp[parity];
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}