#include <iostream>
#include <unordered_map>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string x, y; cin >> x >> y;
    unordered_map<string, int> mp{{"Ocelot", 0}, {"Serval", 1}, {"Lynx", 2}};
    if (mp[x] >= mp[y]) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}

