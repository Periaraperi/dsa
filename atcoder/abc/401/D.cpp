#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <array>
 
using namespace std;

struct info {
    int start;
    int len;
    int max_os;
};
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int o_count {};
    for (int i{}; i<n; ++i) {
        if (s[i] == 'o') {
            ++o_count;
            if (i-1 >= 0 && s[i-1] == '?') {
                s[i-1] = '.';
            }
            if (i+1 < n && s[i+1] == '?') {
                s[i+1] = '.';
            }
        }
    }

    int o_left {k-o_count};
    if (o_left == 0) {
        for (int i{}; i<n; ++i) {
            if (s[i] == '?') s[i] = '.';
        }
        cout << s << '\n';
        return 0;
    }

    vector<info> v;
    int sm{};
    for (int i{}; i<n; ++i) {
        int j {i};
        int cnt {};
        if (s[j] != '?') continue;
        while (s[j] == '?') {
            ++cnt;
            ++j;
        }
        v.push_back({i, cnt, (int)ceil((float)cnt/2.0f)});
        sm += v.back().max_os;
        i = j;
    }
    if (sm == o_left) {
        array<char, 2> symbol {'o', '.'};
        for (const auto& [start, len, max_os]:v) {
            if (len%2 == 1) {
                for (int i{start}, j{}; i<start+len; ++i, j = (j+1)%2) {
                    s[i] = symbol[j];
                }
            }
        }
    }
    cout << s << '\n';
    return 0;
}

