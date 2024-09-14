#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxValue(vector<int>& nums, int k) 
    {
        int N = (int)nums.size();
        int M = (1 << 8) - 1;

        auto generate_dp_table = [&](const vector<int>& v) {
            vector<vector<vector<bool>>> dp(N+1, vector<vector<bool>>(k+1, vector<bool>(M, false)));
            dp[0][0][0] = true;

            for (int i=0; i<N; ++i) {
                dp[i+1] = dp[i];
                for (int len=0; len<k; ++len) {
                    for (int x=0; x<M; ++x) {
                        if (dp[i][len][x]) {
                            dp[i+1][len+1][x | v[i]] = true;
                        }
                    }
                }
            }

            return dp;
        };

        auto nums_reversed{nums};
        reverse(nums_reversed.begin(), nums_reversed.end());

        const auto pref_dp = generate_dp_table(nums);
        const auto suff_dp = generate_dp_table(nums_reversed);

        int ans = 0;
        for (int i=0; i<N; ++i) {
            for (int n=0; n<M; ++n) {
                for (int m=0; m<M; ++m) {
                    if (pref_dp[i][k][n] && suff_dp[N-i][k][m]) {
                        ans = max(ans, n^m);
                    }
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution s{};
}
