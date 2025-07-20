#include <iostream>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> v(n);
    int64_t total {};
    for (auto& i:v) {
        cin >> i;
        total += i;
    }

    // stores indices in each subset
    vector<vector<int>> combinations(1<<n, vector<int>());

    for (int i{}; i<(1<<n); ++i) {
        for (int j{}; j<n; ++j) {
            if ((i & (1<<j)) != 0) {
                combinations[i].push_back(j);
            }
        }
    }

    const int64_t inf {total+1};
    int64_t diff {inf};
    for (const auto& c:combinations) {
        int64_t subset_total {};
        for (const auto& i:c) {
            subset_total += v[i];
        }
        diff = min(diff, abs((total-subset_total) - subset_total));
    }
    cout << diff << '\n';
    return 0;
}

