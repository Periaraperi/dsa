#include <iostream>
#include <string>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;

    for (char c{'a'}; c<='z'; ++c) {
        bool found {false};
        for (const auto& ch:s) {
            if (ch == c) {
                found = true;
                break;
            }
        }
        if (!found) {
            cout << c << '\n';
            return 0;
        }
    }
    return 0;
}

