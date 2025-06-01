#include <iostream>
#include <vector>
 
using namespace std;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    vector<vector<int>> dishes(m);
    vector<vector<int>> graph(n+1);
    vector<int> ing_count(m, 0);
    for (int i{}; i<m; ++i) {
        int k; cin >> k;
        dishes[i].resize(k);
        for (auto& d:dishes[i]) { 
            cin >> d;
            graph[d].push_back(i);
        }
        ing_count[i] = (int)dishes[i].size();
    }
    vector<int> v(n);
    for (auto& i:v) {
        cin >> i;
    }

    int count {};
    for (const auto& i:v) {
        for (const auto& j:graph[i]) {
            --ing_count[j];
            if (ing_count[j] <= 0) ++count;
        }
        cout << count << '\n';
    }

    return 0;
}

