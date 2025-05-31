#include <algorithm>
#include <iostream>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<int> v(n, 0);
    for (int i{}; i<m; ++i) {
        int a, b; cin >> a >> b;
        --a; --b;
        ++v[a];
        if (b+1 < n) --v[b+1];
    }
    for (int i{1}; i<n; ++i) v[i] += v[i-1];
    cout << *min_element(v.begin(), v.end()) << '\n';
    return 0;
}

