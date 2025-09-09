#include <algorithm>
#include <iostream>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<int64_t> blacks(n), whites(m);
    for (auto& i:blacks) cin >> i;
    for (auto& i:whites) cin >> i;
    sort(blacks.begin(), blacks.end());
    sort(whites.begin(), whites.end());

    int64_t total_blacks {};
    int count_blacks {};
    {
        int i{n-1};
        while (i>=0 && blacks[i] >= 0) {
            total_blacks += blacks[i];
            ++count_blacks;
            --i;
        }
    }

    int64_t total_whites {};
    int count_whites {};
    {
        int i{m-1};
        while (i>=0 && whites[i] >= 0) {
            total_whites += whites[i];
            ++count_whites;
            --i;
        }
    }

    if (count_blacks >= count_whites) {
        cout << total_blacks+total_whites << '\n';
    }
    else {
        int i{n-1}, j{m-1};
        int64_t ans {};
        int64_t running_sum {};
        while (i>=0 && j>=0) {
            running_sum += (blacks[i]+whites[j]);
            ans = max(running_sum, ans);
            --i; --j;
        }
        cout << ans << '\n';
    }

    return 0;
}

