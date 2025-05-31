#include <algorithm>
#include <iostream>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<int> v(n);
    vector<int> ans;
    vector<bool> seen(101, false);
    for (auto& i:v) {
        cin >> i;
        if (seen[i]) continue;
        ans.push_back(i);
        seen[i] = true;
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (const auto& i:ans) {
        cout << i << " ";
    }
    cout << '\n';
    return 0;
}

