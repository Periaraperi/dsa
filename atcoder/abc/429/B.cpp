#include <iostream>
#include <vector>
 
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<int> v(n);
    int sm {};
    for (auto& i:v) {
        cin >> i;
        sm += i;
    }
    for (const auto& i:v) {
        if (sm - i == m) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}

