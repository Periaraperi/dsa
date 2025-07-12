#include <iostream>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    int n {(int)s.size()};
    int cnt {};
    for (int i{}; i<n; ++i) {
        int j {i};
        int c {1};
        while (j+1 < n && s[j] == s[j+1]) {
            ++c;
            ++j;
        }
        i = j;
        cnt = max(cnt, c);
    }
    cout << cnt << '\n';
    return 0;
}

