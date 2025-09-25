#include <iostream>
#include <string>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    int n {static_cast<int>(s.size())};
    for (int i{n-1}; i>0; --i) {
        if (s[i]=='A' && s[i-1]=='W') {
            s[i] = 'C';
            s[i-1] = 'A';
        }
    }
    cout << s << '\n';
    return 0;
}

