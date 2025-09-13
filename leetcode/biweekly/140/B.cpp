#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) 
    {
        auto v {maximumHeight};

        sort(v.begin(), v.end());

        long long sm{v[v.size() - 1]};
        for (int i{(int)v.size() - 2}; i>=0; --i) {
            if (v[i] < v[i+1]) { sm += v[i]; continue; }
            else if (v[i] > v[i+1]) v[i] = v[i+1] - 1;
            else if (v[i] == v[i+1]) --v[i];

            if (v[i] == 0) return -1;
            else sm += v[i];
        }
        return sm;
    }
};

int main()
{}
