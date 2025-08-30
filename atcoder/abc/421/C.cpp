#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <numeric>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    string str; cin >> str;

    int64_t final_ans {numeric_limits<int64_t>::max()};
    for (int k{}; k<4; ++k) {
        auto s {str};
        int64_t ans {};
        if (k == 1) {
            reverse(s.begin(), s.end());
        }
        else if (k == 2) {
            swap(s[0], s[1]);
            ++ans;
        }
        else if (k == 3) {
            reverse(s.begin(), s.end());
            swap(s[0], s[1]);
            ++ans;
        }

        set<int> a; 
        set<int> b; 
        
        for (int i{}; i<2*n; ++i) {
            if (s[i] == 'A') a.insert(i);
            else b.insert(i);
        }
        for (int i{1}; i<2*n; ++i) {
            if (s[i] != s[i-1]) continue;
            if (s[i] == 'A') {
                auto it {b.lower_bound(i)};
                swap(s[i], s[*it]);
                ans += (*it - i);
                b.erase(*it);
            }
            else {
                auto it {a.lower_bound(i)};
                swap(s[i], s[*it]);
                ans += (*it - i);
                a.erase(*it);
            }
        }
        final_ans = min(final_ans, ans);
    }

    cout << final_ans << '\n';
    return 0;
}
