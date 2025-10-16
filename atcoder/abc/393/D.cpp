#include <iostream>
#include <vector>
#include <string>
#include <limits>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    string s; cin >> s;
    vector<int64_t> cnt_ones(n+1, 0);
    vector<int64_t> index_sum(n+1, 0);
    for (int i{}; i<n; ++i) {
        cnt_ones[i+1] = cnt_ones[i]+(s[i]-'0');
        index_sum[i+1] = index_sum[i]+(s[i]-'0')*i;
    }
    int64_t ans {numeric_limits<int64_t>::max()};
    for (int i{}; i<n; ++i) {
        if (s[i] == '0') continue;
        const auto j {i+1};

        const auto ones_left {cnt_ones[j-1]};
        const auto l {ones_left*i - index_sum[j-1] - (ones_left*(ones_left+1))/2};

        const auto ones_right {cnt_ones[n]-cnt_ones[j]};
        const auto r {(index_sum[n]-index_sum[j]) - ones_right*i - (ones_right*(ones_right+1))/2};

        ans = min(ans, l+r);
    }
    cout << ans << '\n';
    return 0;
}

