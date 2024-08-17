#include <vector>
using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans(nums.size()-k+1, -1);
        if (k == 1) {
            ans = nums;
            return ans;
        }

        int l = 0;
        int r = 0;
        int j = 0;

        int mx = nums[0];
        while (l<=r && r < (int)nums.size()) {
            if (r-l+1 < k) {
                ++r;
                if (r < (int)nums.size() && nums[r]-1 == nums[r-1]) {
                    mx = nums[r];
                }
                else {
                    l = r;
                    ++j;
                }
            } 
            else {
                if (r < (int)nums.size() && nums[r]-1 == nums[r-1]) {
                    ans[l] = nums[r];
                    ++l;
                    ++r;
                }
                else {
                    l = r;
                }
                ++j;
            }

        }
        
        return ans;
    }
};

int main() 
{
    return 0;
}


