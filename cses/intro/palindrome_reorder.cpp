#include <algorithm>
#include <iostream>
#include <array>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    array<int, 26> freq{};
    string s; cin >> s;
    for (const auto& ch:s) ++freq[ch-'A'];
    string half;
    char mid {' '};
    for (int i{}; i<26; ++i) {
        if (freq[i] > 0) {
            if (freq[i] % 2 == 1) {
                if (mid != ' ') {
                    cout << "NO SOLUTION\n";
                    return 0;
                }
                else {
                    mid = i+'A';
                    continue;
                }
            }
            half += string(freq[i]/2, i+'A');
        }
    }
    cout << half;
    if (mid != ' ') {
        for (int i{}; i<freq[mid-'A']; ++i) {
            cout << mid;
        }
    }
    reverse(half.begin(), half.end());
    cout << half <<  '\n';
    return 0;
}

