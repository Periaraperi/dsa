#include <algorithm>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    int maxPathLength(vector<vector<int>>& coordinates, int k) 
    {
        vector<pair<int, int>> points_before_target; points_before_target.reserve(coordinates.size());
        vector<pair<int, int>> points_after_target; points_after_target.reserve(coordinates.size());
        pair<int, int> target_point = {coordinates[k][0], coordinates[k][1]};
        for (int i=0; i<(int)coordinates.size(); ++i) {
            const auto p = coordinates[i];
            if (k == i) {
                points_before_target.push_back({p[0], p[1]});
                points_after_target.push_back({p[0], p[1]});
            }
            else if (p[0] < target_point.first && p[1] < target_point.second) points_before_target.push_back({p[0], p[1]});
            else if (p[0] > target_point.first && p[1] > target_point.second) points_after_target.push_back({p[0], p[1]});
        }


        auto inc_x_dec_y = [](const pair<int, int>& a, const pair<int, int>& b) -> bool {
            if (a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        };
        sort(points_after_target.begin(), points_after_target.end(), inc_x_dec_y);
        sort(points_before_target.begin(), points_before_target.end(), inc_x_dec_y);

        auto lis_on_y = [](const vector<pair<int, int>>& points) {
            int n = points.size();
            set<int> st;
            for (int i=0; i<n; ++i) {
                auto it = st.lower_bound(points[i].second);
                if (it != st.end()) {
                    st.erase(it);
                    st.insert(points[i].second);
                }
                else st.insert(points[i].second);
            }
            return st.size()-1;
        };

        auto a = lis_on_y(points_before_target);
        auto b = lis_on_y(points_after_target);
        return a + b + 1;
    }
};

int main()
{
    Solution s{};
}
