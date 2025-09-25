#include <iostream>
#include <string>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    int count {};
    for (const auto& i:s) if (i=='2') ++count;
    while (count--) cout << 2;
    cout << '\n';
    return 0;
}

