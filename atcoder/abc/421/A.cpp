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
    for (auto& i:v) cin >> i;
    int m; cin >> m;
    string s; cin >> s;
    if (v[m-1] == s) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}

