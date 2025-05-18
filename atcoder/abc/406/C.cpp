#include <iostream>
#include <vector>
 
using namespace std;

struct Node {
    char dir;
    int64_t length;
};
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> p(n);
    for (auto& i:p) cin >> i;

    vector<Node> up_downs; up_downs.reserve(n);
    {
        vector<char> dir(n);
        for (int i{}; i<n-1; ++i) {
            if (p[i] > p[i+1]) dir[i] = 'd'; // down
            else               dir[i] = 'u'; // up
        }
        if (p[n-1] > p[n-2]) dir[n-1] = 'u';
        else                 dir[n-1] = 'd';

        int i{};
        while (i < n) {
            int len{1};
            int j{i};
            while (j+1 < n && dir[j] == dir[j+1]) {
                ++len;
                ++j;
            }
            up_downs.push_back({dir[i], len});
            i = j+1;
        }
    }

    int64_t ans {0};
    int N {(int)up_downs.size()};
    for (int i{}; i<N; ++i) {
        // we no up_downs oscillate
        if (up_downs[i].dir == 'd' && i-1 >= 0 && i+1 < N) {
            int64_t l {up_downs[i-1].length};
            int64_t r {up_downs[i+1].length};
            if (i+1 == N-1) --r; // edge case
            ans += l*r;
        }
    }
    cout << ans << '\n';

    return 0;
}
