#include <algorithm>
#include <iostream>
#include <set>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A; cin >> A;
    int64_t N; cin >> N;

    auto is_pal = [](const string& s) {
        for (int i{}; i<(int)s.size()/2; ++i) {
            if (s[i] != s[(int)s.size()-i-1]) {
                return false;
            }
        }
        return true;
    };
    
    auto to_base_a = [A](const string& s) {
        int64_t n{stoll(s)};
        string x;
        while (n > 0) {
            x.push_back((n%A)+'0');
            n /= A;
        }
        reverse(x.begin(), x.end());
        return x;
    };

    set<int64_t> visited;

    for (int64_t i{1}; i<1000000; ++i) {
        if (i>N) break;
        auto s{to_string(i)};
        auto rev_s{s}; reverse(rev_s.begin(), rev_s.end());

        if (is_pal(s) && is_pal(to_base_a(s))) {
            visited.insert(i);
        }
        if (auto concat{s+rev_s}; is_pal(to_base_a(concat))) {
            int64_t num {stoll(concat)};
            if (num <= N) {
                visited.insert(num);
            }
        }
        for (int j{}; j<=9; ++j) {
            if (auto concat{s+to_string(j)+rev_s}; is_pal(to_base_a(concat))) {
                int64_t num {stoll(concat)};
                if (num <= N) {
                    visited.insert(num);
                }
                else {
                    break;
                }
            }
        }
    }

    int64_t ans{};
    for (const auto& i:visited) {
        ans += i;
    }
    cout << ans << '\n';

    return 0;
}
