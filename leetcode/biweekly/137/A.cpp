#include <vector>
using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
    std::vector<int> ans(nums.size()-k+1);
        for (int i=0; i<(int)nums.size()-k+1; ++i) {
            int kk = k-1;
            int j = i;
            int mx = nums[i];
            bool ok = true;
            while (kk--) {
                if (j+1 < (int)nums.size() && nums[j]+1 == nums[j+1]) {
                    mx = max(mx, nums[j+1]);
                }
                else {
                    ok = false;
                    break;
                }
                ++j;
            }
            if (!ok) ans[i] = -1;
            else ans[i] = mx;
        } 
        return ans;
    }
};

int main() 
{
    return 0;
}

