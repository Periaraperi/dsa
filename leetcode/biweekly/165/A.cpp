#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int smallestAbsent(vector<int>& v) {
        sort(v.begin(), v.end());
        int sm {accumulate(v.begin(), v.end(), 0)};
        const int N {static_cast<int>(v.size())};
        const auto avg {sm/N};
        
        int i{avg}; 
        bool ok {false};
        while (!ok) {
            bool f{true};
            ++i;
            for (int j{}; j<N; ++j) {
                if (v[j] == i) {
                    f = false;
                    break;
                }
            }
            ok = f;
            if (i <= 0) ok = false;
        }
        return i;
    }
};
