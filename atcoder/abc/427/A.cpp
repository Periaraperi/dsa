#include <iostream>
#include <string>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    for (int i{}; i<static_cast<int>(s.size()); ++i) {
        if (i == static_cast<int>(s.size())/2) continue;
        cout << s[i];
    }
    cout << '\n';
    return 0;
}

