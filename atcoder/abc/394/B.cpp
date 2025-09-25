#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<string> v(n);
    for (auto& s:v) cin >> s;
    sort(v.begin(), v.end(), [](const string& a, const string& b) { return a.size()<b.size(); });
    for (const auto& s:v) cout << s;
    cout << '\n';
    return 0;
}

