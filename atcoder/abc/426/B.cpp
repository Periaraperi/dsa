#include <iostream>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    vector<int> f(27, 0);
    for (const auto& c:s) {
        ++f[c-'a'];
    }
    for (size_t i{}; i<f.size(); ++i) {
        if (f[i] == 1) {
            cout << static_cast<char>(('a'+i)) << '\n';
            break;
        }
    }
    return 0;
}

