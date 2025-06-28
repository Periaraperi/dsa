#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s, t; cin >> s >> t;

    vector<bool> is(126, false);

    for (const auto& ch:t) {
        is[ch] = true;
    }

    bool ok {true};
    for (int i{1}; i<(int)s.size(); ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z' && !is[s[i-1]]) {
            ok = false;
        }
    }
    if (ok) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}

