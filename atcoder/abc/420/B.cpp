#include <algorithm>
#include <iostream>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<string> v(n);
    for (int i{}; i<n; ++i) {
        cin >> v[i];
    }

    vector<int> points(n+1, 0);

    for (int i{}; i<m; ++i) {
        int co{}, cz{};
        for (int j{}; j<n; ++j) {
            const auto& str {v[j]};
            if (str[i] == '0') {
                ++cz;
            }
            else {
                ++co;
            }
        }
        char winning_char;
        if (co < cz) {
            winning_char = '1';
        }
        else {
            winning_char = '0';
        }

        for (int j{}; j<n; ++j) {
            const auto& str {v[j]};
            if (str[i] == winning_char) {
                ++points[j];
            }
        }
    }

    int max_p {};
    for (const auto& i:points) {
        max_p = max(max_p, i);
    }
    
    vector<int> winners;
    for (int i{}; i<n; ++i) {
        if (points[i] == max_p) 
            winners.push_back(i);
    }
    sort(winners.begin(), winners.end());
    for (const auto& i:winners) {
        cout << i + 1 << " ";
    }
    cout << '\n';
    return 0;
}

