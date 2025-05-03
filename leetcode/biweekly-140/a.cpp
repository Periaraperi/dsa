#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minElement(vector<int>& nums) 
    {
        auto dig_sum = [](int n) {
            int s{};
            while (n > 0) {
                s += n%10;
                n /= 10;
            }
            return s;
        };

        int mn{1000000000};
        for (int i{}; i<(int)nums.size(); ++i) {
            mn = min(mn, dig_sum(nums[i]));
        }

        return mn;
    }
};

int main()
{}
