/* Sandro's Biography */

#include <iostream>
#include <string>
#include <limits>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    const string t{"Sandro"};
    int n {static_cast<int>(s.size())};
    int total{numeric_limits<int>::max()};

    int l{0}, r{5};
    while (r<n) {
        int cost {};
        if (s[l] != 'S') {
            if (s[l]>='A' && s[l]<='Z') cost += 5;
            else {
                if (s[l]=='s') cost += 5;
                else cost += 10;
            }
        }
        for (int i{l+1}, j{1}; i<=r && j<static_cast<int>(t.size()); ++i, ++j) {
            if (s[i] != t[j]) {
                if (s[i]>='a' && s[i]<='z') cost += 5;
                else {
                    if (s[i]==toupper(t[j])) cost += 5;
                    else cost += 10;
                }
            }
        }
        total = min(total, cost);
        ++l; ++r;
    }
    cout << total << '\n';

    return 0;
}

