#include <bits/stdc++.h>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> v = {"ACE", "BDF", "CEG", "DFA", "EGB", "FAC","GBD"};
    string s; cin >> s;
    for (auto& str:v) {
        if (s==str) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}

