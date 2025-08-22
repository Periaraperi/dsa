#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
 
using namespace std;

void recurse(int k, vector<string>& v, vector<string>& current, vector<string>& strs, vector<bool>& used)
{
    if ((int)current.size() == k) {
        strs.emplace_back();
        for (const auto& s:current) {
            strs.back().append(s);
        }
        return;
    }

    const int n {(int)v.size()};
    for (int j{}; j<n; ++j) {
        current.emplace_back(v[j]);
        recurse(k, v, current, strs, used);
        current.pop_back();
    }
}
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K, X; cin >> N >> K >> X;
    vector<string> v(N);
    for (auto& i:v) cin >> i;

    vector<string> tmp; tmp.reserve(pow(N, K));
    vector<string> strs; strs.reserve(pow(N, K));
    vector<bool> used(N, false);
    recurse(K, v, tmp, strs, used);
    sort(strs.begin(), strs.end());
    cout << strs[X-1] << '\n';

    return 0;
}

