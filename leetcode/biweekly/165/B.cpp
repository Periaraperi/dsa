#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int minArrivalsToDiscard(vector<int>& v, int w, int m) {
        const int N {static_cast<int>(v.size())};
        const int MAX {*max_element(v.begin(), v.end())};
        vector<int> freq(MAX+1, 0);
        vector<bool> discarded(N, false);
        int ans {};
        for (int i{}; i<w; ++i) {
            ++freq[v[i]];
            if (freq[v[i]] > m) {
                --freq[v[i]];
                ++ans;
                discarded[i] = true;
            }
        }

        int l{1};
        int r{w};
        while (r<N) {
            if (!discarded[l-1]) --freq[v[l-1]];
            ++freq[v[r]];
            if (freq[v[r]] > m) {
                discarded[r] = true;
                --freq[v[r]];
                ++ans;
            }
            ++l; ++r;
        }
        
        return ans;
    }
};
