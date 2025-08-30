#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <limits>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    string str; cin >> str;

    auto f = [n](string s) {
        set<int> a; 
        set<int> b; 
        
        for (int i{}; i<2*n; ++i) {
            if (s[i] == 'A') a.insert(i);
            else b.insert(i);
        }
        
        set<int>::iterator it;
        int64_t ans{};
        for (int i{1}; i<2*n; ++i) {
            if (s[i] != s[i-1]) continue;

            int j{};
            if (s[i] == 'A') {
                it = b.lower_bound(i);
                j = *it;
                b.erase(it);
            }
            else {
                it = a.lower_bound(i);
                j = *it;
                a.erase(it);
            }
            swap(s[i], s[j]);
            ans += (j - i);
        }
        return ans;
    };

    int64_t final_ans {numeric_limits<int64_t>::max()};
    auto s2 {str}; 

    final_ans = min(final_ans, f(str));
    swap(str[0], str[1]);
    final_ans = min(final_ans, f(str)+1);

    reverse(s2.begin(), s2.end());
    final_ans = min(final_ans, f(s2));
    swap(s2[0], s2[1]);
    final_ans = min(final_ans, f(s2)+1);

    cout << final_ans << '\n';
    return 0;
}
