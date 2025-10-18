#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    string s; cin >> s;
    map<string, int> mp;

    for (int i{}; i<n-k+1; ++i) {
        ++mp[s.substr(i, k)];
    }

    int cnt {};
    for (const auto& it:mp) {
        cnt = max(cnt, it.second);
    }

    vector<string> strings;
    for (const auto& it:mp) {
        if (it.second == cnt) strings.push_back(it.first);
    }
    sort(strings.begin(), strings.end());
    cout << cnt << '\n';
    for (const auto& str:strings) cout << str << " ";
    cout << '\n';

    return 0;
}

