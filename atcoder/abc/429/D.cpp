#include <iostream>
#include <vector>
#include <map>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, c; 
    int64_t m;
    cin >> n >> m >> c;
    vector<int64_t> v(n);
    map<int64_t, int> cnt;
    cnt[m-1] = 0;
    for (auto& i:v) {
        cin >> i;
        ++cnt[i];
    }
    struct info {
        int64_t m;
        int64_t freq;
    };
    vector<info> a;
    for (const auto& [k, val]:cnt) {
        a.push_back({k, val});
    }
    int a_len {static_cast<int>(a.size())};
    vector<int64_t> pref_sum(a_len+1, 0);
    for (int i{1}; i<=a_len; ++i) {
        pref_sum[i] = pref_sum[i-1]+a[i-1].freq;
    }

    auto get_count = [&pref_sum, a_len, c](int start) {
        int64_t count {};
        count = pref_sum[a_len]-pref_sum[start-1];
        
        // [start, end]
        {
            int lo {start};
            int hi {a_len};
            while (lo<=hi) {
                const auto mid {(lo+hi)/2};
                const auto x {pref_sum[mid]-pref_sum[start-1]};
                if (x < c) {
                    lo = mid+1;
                }
                else {
                    hi = mid-1;
                    count = x;
                }
            }
        }
        // [0, start-1]
        if (count < c) {
            int64_t count2 {pref_sum[start-1]};
            int lo {1};
            int hi {start-1};
            while (lo<=hi) {
                const auto mid {(lo+hi)/2};
                if (pref_sum[mid]+count < c) {
                    lo = mid+1;
                }
                else {
                    hi = mid-1;
                    count2 = pref_sum[mid];
                }
            }
            count += count2;
        }
        return count;
    };

    vector<int64_t> xs(a_len, 0);
    for (int i{}; i<a_len; ++i) {
        xs[i] = get_count(i+1);
    }

    int64_t ans {};
    int64_t t {};
    for (int i{}; i<a_len; ++i) {
        ans += ((a[i].m-t+1)*xs[i]);
        t = a[i].m+1;
    }
    cout << ans << '\n';
    return 0;
}

