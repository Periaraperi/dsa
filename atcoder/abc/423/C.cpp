#include <iostream>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, r; cin >> n >> r;
    vector<int> v(n);
    for (auto& i:v) cin >> i;

    int last_open_right {-1};
    for (int i{r+1}; i<=n; ++i) {
        if (v[i-1] == 0) {
            last_open_right = i;
        }
    }
    int last_open_left {-1};
    for (int i{r-1}; i>=0; --i) {
        if (v[i] == 0) {
            last_open_left = i;
        }
    }

    int ans {};
    if (last_open_right != -1) {
        for (int i{r}; i<last_open_right; ++i) {
            if (v[i] == 1) {
                ++ans;
            }
        }
        ans += (last_open_right-r);
    }
    if (last_open_left != -1) {
        for (int i{r}; i>last_open_left; --i) {
            if (v[i-1] == 1) {
                ++ans;
            }
        }
        ans += (r-last_open_left);
    }
    cout << ans << '\n';
    return 0;
}
