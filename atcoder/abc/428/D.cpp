#include <cmath>
#include <iostream>
#include <vector>
 
using namespace std;

int64_t count(int64_t c, int64_t d)
{
    auto f = [](int64_t a, int64_t b) {
        return stoll(to_string(a)+to_string(b));
    };
    auto digit_count = [](int64_t a) {
        int counter {};
        while (a>0) {
            a /= 10;
            ++counter;
        }
        return counter;
    };
    struct range {
        int64_t l {};
        int64_t r {};
    };
    vector<range> ranges;
    {
        int64_t mn {f(c, c+1)};
        int64_t mx {f(c, c+d)};
        int mn_digit_count {digit_count(c+1)};
        int mx_digit_count {digit_count(c+d)};
        int64_t m {static_cast<int64_t>(pow(10LL, mn_digit_count))};

        ranges.push_back({mn, min(c*m+(m-1), mx)});
        for (int i{mn_digit_count+1}; i<mx_digit_count; ++i) {
            m *= 10;
            ranges.push_back({c*m+(m/10), c*m+(m-1)});
        }
        m *= 10;
        if (c*m+(m/10) <= mx) ranges.push_back({c*m+(m/10), mx});
    }

    int64_t ans {};
    for (const auto& [l, r]:ranges) {
        int64_t sqrt_left {static_cast<int64_t>(ceil(sqrt(static_cast<long double>(l))))};
        int64_t sqrt_right {static_cast<int64_t>(floor(sqrt(static_cast<long double>(r))))};
        ans += (sqrt_right-sqrt_left+1);
    }
    return ans;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t{1}; cin >> t;
    while (t--) {
        int64_t c, d; cin >> c >> d;
        cout << count(c, d) << '\n';
    }
    return 0;
}

