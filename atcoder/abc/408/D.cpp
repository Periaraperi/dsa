#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        int total_ones{};
        vector<int> v; v.reserve(s.size());
        for (int i{}; i<n; ++i) {
            if (s[i] == '1') {
                v.push_back(1);
                ++total_ones;
            }
            else {
                v.push_back(-1);
            }
        }

        constexpr int INF {10000000};
        int mx {-INF};
        int running_sum {};
        for (int i{}; i<n; ++i) {
            if (v[i] > running_sum) running_sum = v[i];
            else running_sum += v[i];
            mx = max(mx, running_sum);
        }
        mx = max(mx, 0); // case when input is all zeroes

        cout << total_ones - mx << '\n';
    }

    return 0;
}

